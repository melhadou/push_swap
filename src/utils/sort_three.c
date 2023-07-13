/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhadou <melhadou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 11:45:44 by melhadou          #+#    #+#             */
/*   Updated: 2023/07/13 13:01:58 by melhadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

void	sort_three(t_stack **a)
{
	/* example 
	 * ** Frist example**
	 * 	7
	 * 	3
	 * 	9
	 * ** second example**
	 * 	7
	 * 	9
	 * 	3
	 * ** third example**
	 * 	3
	 * 	9
	 * 	7
	 * ** fourth example**
	 * 	9
	 * 	3
	 * 	7
	 * ** fifth example**
	 * 	9
	 * 	7
	 * 	3
	 * */
	if ((*a)->val > (*a)->next->val && (*a)->val < (*a)->next->next->val)
		sa(a, 1);
	else if ((*a)->val < (*a)->next->val && (*a)->val > (*a)->next->next->val)
		rra(a, 1);
	else if ((*a)->val < (*a)->next->val && (*a)->next->val > (*a)->next->next->val)
	{
		sa(a, 1);
		ra(a, 1);
	}
	else if ((*a)->val > (*a)->next->val && (*a)->next->val < (*a)->next->next->val)
		ra(a, 1);
	else if ((*a)->val > (*a)->next->val && (*a)->next->val > (*a)->next->next->val)
	{
		sa(a, 1);
		rra(a, 1);
	}
}
