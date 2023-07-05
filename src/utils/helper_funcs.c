/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhadou <melhadou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 14:58:25 by melhadou          #+#    #+#             */
/*   Updated: 2023/07/04 15:05:02 by melhadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int find_max(t_stack a)
{
	int max;
	t_stack *tmp;

	tmp = &a;
	while (tmp)
	{
		if (tmp->rank == 0)
		{
			max = tmp->val;
			break ;
		}
		tmp = tmp->next;
	}
	tmp = &a;
	while (tmp)
	{
		if (tmp->val > max && tmp->rank != 0)
			max = tmp->val;
		tmp = tmp->next;
	}
	return (max);
}
