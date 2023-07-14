/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhadou <melhadou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 11:45:44 by melhadou          #+#    #+#             */
/*   Updated: 2023/07/14 15:17:38 by melhadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// normed
void	sort_three(t_stack **a)
{
	if ((*a)->val > (*a)->next->val \
		&& (*a)->val < (*a)->next->next->val)
		sa(a, 1);
	else if ((*a)->val < (*a)->next->val \
			&& (*a)->val > (*a)->next->next->val)
		rra(a, 1);
	else if ((*a)->val < (*a)->next->val \
			&& (*a)->next->val > (*a)->next->next->val)
	{
		sa(a, 1);
		ra(a, 1);
	}
	else if ((*a)->val > (*a)->next->val \
			&& (*a)->next->val < (*a)->next->next->val)
		ra(a, 1);
	else if ((*a)->val > (*a)->next->val \
			&& (*a)->next->val > (*a)->next->next->val)
	{
		sa(a, 1);
		rra(a, 1);
	}
}
