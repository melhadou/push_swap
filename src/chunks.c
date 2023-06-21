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

	res[0].size = length;
	
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

	printf("middle %d\n", middle);
	return (middle);
}

void	send_to_top(int pos, t_stack **a, t_stack **b)
{
	if (pos < 0)
		return ;
	while (pos)
	{
		ra(a, 1);
		pos--;
	}
	pb(b, a, 1);
}

void	send_to_tail(int pos, t_stack **a, t_stack **b)
{
	if (pos < 0)
		return ;
	while (pos)
	{
		rra(a, 1);
		pos--;
	}
	pb(b, a, 1);
}

void	first_phase(t_stack **a, t_stack **b, int phase)
{
	t_chunks *ch;
	int top_pos;
	int tail_pos;

	int i = 0;
	ch = find_chunks(a);
	while (1)
	{
		top_pos = find_from_top(*a, ch[phase]);
		tail_pos = find_from_tail(*a, ch[phase]);
		printf("tail %d, top %d\n", tail_pos, top_pos);
		if (tail_pos == -1 && top_pos == -1)
			break ;
		if (tail_pos < top_pos)
			send_to_tail(tail_pos, a, b);
		else
			send_to_top(top_pos, a, b);
		if (i == 100)
		 break;
		i++;
	}
}
