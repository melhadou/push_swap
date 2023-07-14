/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhadou <melhadou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 12:07:04 by melhadou          #+#    #+#             */
/*   Updated: 2023/07/14 12:14:36 by melhadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// normed
void	sa(t_stack **a, int print)
{
	int	pt;
	int	pt_rank;

	if (!*a || !*a || (lst_size(*a) == 1))
		return ;
	pt = (*a)->next->val;
	pt_rank = (*a)->next->rank;
	(*a)->next->val = (*a)->val;
	(*a)->next->rank = (*a)->rank;
	(*a)->val = pt;
	(*a)->rank = pt_rank;
	if (print)
		write(1, "sa\n", 3);
}

void	sb(t_stack **b, int print)
{
	int	pt;
	int	pt_rank;

	if (!b || !*b || (lst_size(*b) == 1))
		return ;
	pt = (*b)->next->val;
	pt_rank = (*b)->next->rank;
	(*b)->next->val = (*b)->val;
	(*b)->next->rank = (*b)->rank;
	(*b)->val = pt;
	(*b)->rank = pt_rank;
	if (print)
		write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b)
{
	sa(a, 0);
	sb(b, 0);
	write(1, "ss\n", 3);
}
