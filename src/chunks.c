#include "push_swap.h"

t_chunks	*find_chunks(t_stack **a)
{
	t_chunks *res;
	int length;
	int i;

	i = 0;
	length = lst_size(*a) / CHUNK_SIZE;
	res = malloc(sizeof(t_chunks) * length);
	if (!res)
		return NULL;
	res[i].size = length;
	while (i < length)
	{
		res[i].start = CHUNK_SIZE * i;
		res[i].end = CHUNK_SIZE * (i + 1);
		i++;
	}
	return (res);
}

int	find_from_top(t_stack *a, t_chunks chunk)
{
	int size;
	int pos;
	t_stack *tmp;

	tmp = a;
	pos = 0;
	size = lst_size(tmp);
	size /= 2;
	
	while (tmp && pos < size)
	{
		if (tmp->rank >= chunk.start && tmp->rank <= chunk.end)
			return pos;
		tmp = tmp->next;
		pos++;
	}
	return (-1);
}

int	find_from_tail(t_stack *a, t_chunks chunk)
{
	int size;
	int middle;
	t_stack *tmp;

	tmp = a;
	size = lst_size(tmp);
	middle = size / 2;

	// get to the middle
	while (tmp)
	{
		if (!--middle)
			break ;
		tmp = tmp->next;
	}

	while (tmp)
	{
		if (tmp->rank >= chunk.start && tmp->rank <= chunk.end)
			middle = 0;
		middle++;
		tmp = tmp->next;
	}
	// printf("middle %d\n", middle);
	return (middle);
}


void	first_phase(t_stack **a)
{
	t_chunks *ch;
	int	top_pos;
	int	tail_pos;
	int	phase;
	int i;

	i = 0;
	ch = find_chunks(a);
	phase = ch[0].size;
	printf("phase %d\n", phase);
	// while (phase)
	// {
		while (1)
		{
			top_pos = find_from_top(*a, ch[phase]);
			tail_pos = find_from_tail(*a, ch[phase]);
			// printf("ch[phase] = %d, tail_pos = %d, top %d\n",ch[phase].end, tail_pos, top_pos);
			if (tail_pos == 1 && top_pos == -1)
				break ;
			if (tail_pos < top_pos)
				send_to_tail(tail_pos, a);
			else
				send_to_top(top_pos, a);
			if (i == 100)
				break ;
			i++;
		}
	// 	phase--;
	// }
}
