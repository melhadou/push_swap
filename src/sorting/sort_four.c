/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhadou <melhadou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 11:37:34 by melhadou          #+#    #+#             */
/*   Updated: 2023/07/13 15:20:16 by melhadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_four(t_stack **a, t_stack **b)
{
	push_smallest(a, b);
	sort_three(a);
	pa(a, b, 1);
}

void	push_smallest(t_stack **a, t_stack **b)
{
	t_stack *tmp;
	int rank;

	rank = (*a)->rank;
	tmp = *a;
	while (tmp)
	{
		if (tmp->rank <= rank)
			rank = tmp->rank;
		tmp = tmp->next;
	}
	while (*a)
	{
		if ((*a)->rank == rank)
		{
			pb(b, a, 1);
			return ;
		}
		ra(a, 1);
	}
}
