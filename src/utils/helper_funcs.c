/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhadou <melhadou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 14:58:25 by melhadou          #+#    #+#             */
/*   Updated: 2023/07/14 12:28:12 by melhadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// normed
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
	int	size;

	size = lst_size(*b);
	if (pos > size / 2)
		send_to_tail(size - pos, b);
	else
		send_to_top(pos, b);
}

int	nb_rank_position(t_stack *stack, int rank)
{
	int	pos;

	pos = 1;
	while (stack)
	{
		if (stack->rank == rank)
			return (pos);
		stack = stack->next;
		pos++;
	}
	return (-1);
}

int	check_is_ranked(t_stack *a)
{
	int	i;

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
