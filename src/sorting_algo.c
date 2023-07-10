/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhadou <melhadou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 11:32:25 by melhadou          #+#    #+#             */
/*   Updated: 2023/07/10 19:45:38 by melhadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_doubles(t_stack *head)
{
	t_stack	*tmp;
	t_stack	*current;

	tmp = head;
	current = head;

	while (current)
	{
		tmp = current->next;
		while (tmp)
		{
			if (tmp->val == current->val)
			{
				return 1;
			}
			tmp = tmp->next;
		}
		current = current->next;
	}

	return 0;
}

void	copy_rank(t_stack *head1, t_stack *head2)
{
 	t_stack *current1;
 	t_stack *current2;

	current1 = head1;
  while (current1 != NULL) {
		current2 = head2;
		while (current2 != NULL) {
			if (current1->val == current2->val)
				current2->rank = current1->rank;
			current2 = current2->next;
		}
		current1 = current1->next;
  }
}
