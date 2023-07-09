/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhadou <melhadou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 14:58:25 by melhadou          #+#    #+#             */
/*   Updated: 2023/07/08 12:23:13 by melhadou         ###   ########.fr       */
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

void	send_to_top(int pos, t_stack **a)
{
	if (pos < 0)
		return ;
	while (pos)
	{
		ra(a, 1);
		pos--;
	}
}

void	send_to_tail(int pos, t_stack **a)
{
	if (pos < 0)
		return ;
	while (pos)
	{
		rra(a, 1);
		pos--;
	}
}

void	send_to_top_or_tail(int pos, t_stack **a)
{
	int size;

	size = lst_size(*a);
	if (pos > size / 2)
		send_to_tail(size - pos, a);
	else
		send_to_top(pos, a);
}

void	send_range(int start, int end, t_stack **a, t_stack **b)
{
	int i;
	int size;
	t_stack *tmp;

	i = 0;
	size = lst_size(*a);
	if (start < 0 || start > size || end < 0 || end > size )
		return ;
	while (i <= end - start)
	{
		tmp = *a;
		while (tmp)
		{
			if (tmp->rank == i + start)
			{
				pb(b, a, 1);
				if (tmp->rank > size / 2)
					rb(b, 1);
			}
			tmp = tmp->next;
		}
		i++;
	}
}

void	send_all(t_stack **a, t_stack **b)
{
	int size;
	int end;
	int start;

	size = lst_size(*a);
	start = 0;
	end = 5;
	while (1)
	{
		if (end > size)
			end = size;
		printf("start = %d , end = %d, size = %d \n", start, end, size);
		send_range(start , end, a, b);
		start += 5;
		end += 5;
		if (start >= size)
			break ;
	}
}
