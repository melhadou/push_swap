/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_others.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhadou <melhadou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 11:37:24 by melhadou          #+#    #+#             */
/*   Updated: 2023/07/14 12:35:45 by melhadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// normed
void	send_range(int start, int end, t_stack **a, t_stack **b)
{
	int	size;

	size = lst_size(*a);
	while (*a && size)
	{
		if ((*a)->rank >= start && (*a)->rank <= end)
		{
			pb(b, a, 1);
			if ((*b)->rank < (start + end) / 2)
				rb(b, 1);
		}
		else
			ra(a, 1);
		size--;
	}
}

void	send_all(t_stack **a, t_stack **b)
{
	int	size;
	int	end;
	int	start;

	size = lst_size(*a);
	start = size / 2;
	end = size / 2;
	while (size)
	{
		start -= CHUNK_SIZE;
		end += CHUNK_SIZE;
		send_range(start, end, a, b);
		size = lst_size(*a);
	}
	return_to_a(a, b);
}

void	return_to_a_helper(t_stack **a, t_stack **b, int size_b)
{
	int	size;

	size = 0;
	while (*b)
	{
		size = lst_size(*b);
		if ((*b)->rank + 1 == (*a)->rank)
			pa(a, b, 1);
		else if (lst_last_node(*a)->rank < (*b)->rank \
					|| lst_last_node(*a)->rank == size_b)
		{
			pa(a, b, 1);
			ra(a, 1);
		}
		else if (nb_rank_position(*b, (*a)->rank - 1) > (size / 2))
			rrb(b, 1);
		else if (lst_last_node(*a)->rank == (*a)->rank - 1)
			rra(a, 1);
		else
			rb(b, 1);
	}
}

void	return_to_a(t_stack **a, t_stack **b)
{
	int	size_b;

	size_b = lst_size(*b);
	while (1)
	{
		if ((*b)->rank == lst_size(*b))
		{
			pa(a, b, 1);
			break ;
		}
		rb(b, 1);
	}
	return_to_a_helper(a, b, size_b);
	while ((*a)->rank != 1)
		rra(a, 1);
}
