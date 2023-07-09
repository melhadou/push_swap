/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhadou <melhadou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 11:32:22 by melhadou          #+#    #+#             */
/*   Updated: 2023/07/08 11:32:32 by melhadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *lst_new(void)
{
	t_stack *tmp;
	tmp = malloc(sizeof(t_stack));
	tmp->val = 0;
	tmp->rank = 0;
	tmp->next = NULL;
	return tmp;
}

t_stack	*lst_last_node(t_stack *lst)
{
	t_stack	*tmp;

	if (!lst)
		return (NULL);
	tmp = lst;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

void lst_add_back(t_stack **lst, t_stack *new)
{
	t_stack *tmp;

	if (!lst || !new)
		return;
	if (!*lst) // If lst is NULL, assign new to it directly
	{
		*lst = new;
		return;
	}
	tmp = lst_last_node(*lst);
	tmp->next = new;
}

int	lst_size(t_stack *lst)
{
	int	size;
	t_stack *tmp;

	size = 0;
	tmp = lst;
	while (tmp)
	{
		size++;
		tmp = tmp->next;
	}
	return size;
}

void lst_free(t_stack **stack)
{
	t_stack *tmp;

	tmp = *stack;
	while (tmp)
	{
		free(tmp);
		tmp = (*stack)->next;
	}
	free(stack);
	free(tmp);
}
