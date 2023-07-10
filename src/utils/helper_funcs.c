/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhadou <melhadou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 14:58:25 by melhadou          #+#    #+#             */
/*   Updated: 2023/07/10 19:45:17 by melhadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max(t_stack *a)
{
	int max;
	t_stack *tmp;

	tmp = a;
	max = 0;
	while (tmp)
	{
		if (tmp->rank == 0)
		{
			max = tmp->val;
			break ;
		}
		tmp = tmp->next;
	}
	tmp = a;
	while (tmp)
	{
		if (tmp->val > max && tmp->rank == 0)
			max = tmp->val;
		tmp = tmp->next;
	}
	return (max);
}

void	set_rank(t_stack *a)
{
	int size;
	int max;
	t_stack *tmp;

	size = lst_size(a);

	while (size)
	{
		tmp = a;
		max = find_max(tmp);
		while (tmp)
		{
			if (tmp->val == max && tmp->rank == 0)
				tmp->rank = size--;
			tmp  = tmp->next;
		}
	}
}


// functon that caluclate the cost of sending the desired number. and it finds it by its rank
// and check how much instruction that will be needed to send it from a to  b. and it checks 
// how to send . is it by ra or rra.

int	nt_instruction(t_stack *a, int rank)
{
	int cost;
	t_stack *tmp;

	tmp = a;
	cost = 0;
	while (tmp)
	{
		if (tmp->rank == rank)
			break ;
		cost++;
		tmp = tmp->next;
	}

	return (cost);
}

void	send_to_top(int pos, t_stack **b)
{
	if (pos < 0)
		return ;
	while (pos)
	{
		rb(b, 1);
		pos--;
	}
}

void	send_to_tail(int pos, t_stack **b)
{
	if (pos < 0)
		return ;
	while (pos)
	{
		rrb(b, 1);
		pos--;
	}
}

void	send_to_top_or_tail(int pos, t_stack **b)
{
	int size;

	size = lst_size(*b);
	if (pos > size / 2)
		send_to_tail(size - pos, b);
	else
		send_to_top(pos, b);
}

void	send_range(int start, int end, t_stack **a, t_stack **b)
{
	int size;

	size = lst_size(*a);
	while(*a && size)
	{
		if ((*a)->rank >= start && (*a)->rank <= end)
		{
			pb(b, a, 1);
			if ((*b)->rank < (start + end) / 2 )
				rb(b, 1);
		}
		else
			ra(a, 1);
		size--;
	}
}

void	send_all(t_stack **a, t_stack **b)
{
	int size;
	int end;
	int start;

	size = lst_size(*a);
	start = size / 2;
	end = size / 2;
	while (size)
	{
		start -= CHUNK_SIZE;
		end += CHUNK_SIZE;
		// printf("size %d\t start -> %d\t end -> %d\n",size,start, end);
		send_range(start, end, a, b);
		size = lst_size(*a);
	}
	return_to_a(a, b);
}

int nb_rank_position(t_stack *stack, int rank)
{
	int pos;

	pos = 1;
	while (stack)
	{
		if (stack->rank == rank)
			return (pos);
		stack = stack->next;
		pos++;
	}
	return (pos);
}

void	return_to_a(t_stack **a, t_stack **b)
{
	int size;
	int nb_count;

	size = 0;
	nb_count = lst_size(*b);
	while (1)
	{
		if ((*b)->rank == lst_size(*b))
		{
			pa(a, b, 1);
			break ;
		}
		rb(b, 1);
	}
	
	while (*b)
	{
		size = lst_size(*b);
		if ((*b)->rank + 1 == (*a)->rank)
			pa(a, b, 1);
		else if (lst_last_node(*a)->rank == (*a)->rank - 1)
			rra(a, 1);
		else if (lst_last_node(*a)->rank == nb_count)
		{
			pa(a, b, 1);
			ra(a, 1);
		}
		else if (lst_last_node(*a)->rank < (*b)->rank)
		{
			pa(a, b, 1);
			ra(a, 1);
		}
		else if (nb_rank_position(*b, (*a)->rank - 1) > size / 2)
			rrb(b, 1);
		else
			rb(b, 1);
	}
}

int	check_is_ranked(t_stack *a)
{
	int i;

	i = 1;
	while (a)
	{
		if (a->rank != i)
			return (1);
		a = a->next;
		i++;
	}
	return (0);
}
