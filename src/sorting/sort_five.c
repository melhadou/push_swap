/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhadou <melhadou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 11:37:15 by melhadou          #+#    #+#             */
/*   Updated: 2023/07/14 12:16:41 by melhadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// normed
void	sort_five(t_stack **a, t_stack **b)
{
	push_smallest(a, b);
	sort_four(a, b);
	pa(a, b, 1);
}
