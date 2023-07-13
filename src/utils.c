/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhadou <melhadou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 11:32:29 by melhadou          #+#    #+#             */
/*   Updated: 2023/07/13 12:55:55 by melhadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **a,int print)
{
	int pt;
	int pt_rank;

	if (!*a || !*a || (lst_size(*a) == 1))
		return;
	pt = (*a)->next->val;
	pt_rank = (*a)->next->rank;
	(*a)->next->val = (*a)->val;
	(*a)->next->rank = (*a)->rank;
	(*a)->val = pt;
	(*a)->rank = pt_rank;
	if (print)
		write(1, "sa\n",3);
}

void	sb(t_stack **b, int print)
{
	int pt;
	int pt_rank;

	if (!b || !*b || (lst_size(*b) == 1))
		return;
	pt = (*b)->next->val;
	pt_rank = (*b)->next->rank;
	(*b)->next->val = (*b)->val;
	(*b)->next->rank = (*b)->rank;
	(*b)->val = pt;
	(*b)->rank = pt_rank;
	if (print)
		write(1, "sb\n",3);
}

void ss(t_stack **a, t_stack **b)
{
	sa(a, 0);
	sb(b, 0);
	write(1, "ss\n",3);
}

void	pb(t_stack **b, t_stack **a, int print)
{
	t_stack *tmp;

	if (!a || !*a || !b)
		return;
	// keep the old stuff of a
	tmp = *a;
	(*a) = (*a)->next;
	// keep the old stuff of b
	tmp->next = *b;
	*b = tmp;
	if (print)
		write(1, "pb\n", 3);
}

void	pa(t_stack **a, t_stack **b, int print)
{
	t_stack *tmp;

	if (!b || !*b || !a)
		return;
	// keep the old stuff of b
	tmp = *b;
	(*b) = (*b)->next;
	// keep the old stuff of a
	tmp->next = *a;
	*a = tmp;
	if (print)
		write(1, "pa\n", 3);
}

void ra(t_stack **a, int print)
{
	t_stack *tmp;

	if (!a || !*a)
		return ;
	if (lst_size(*a) == 1)
		return ;
	tmp = lst_last_node(*a);
	tmp->next = (*a);
	(*a) = (*a)->next;
	tmp->next->next = NULL;
	if (print)
		write(1, "ra\n", 3);
}

void rb(t_stack **b, int print)
{
	t_stack *tmp;

	if (!b || !*b)
		return ;
	if (lst_size(*b) == 1)
		return ;
	tmp = lst_last_node(*b);
	tmp->next = (*b);
	(*b) = (*b)->next;
	tmp->next->next = NULL;
	if (print)
		write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b)
{
	ra(a, 0);
	rb(b, 0);
	write(1, "rr\n", 3);
}

void rra(t_stack **a, int print)
{
	t_stack *b_lst;

	if (!a || !*a)
		return ;
	if (lst_size(*a) == 1)
		return ;
	b_lst = (*a);
	while (b_lst->next->next)
		b_lst = b_lst->next;
	b_lst->next->next = (*a);
	(*a) = b_lst->next;
	b_lst->next = NULL;
	
	if (print)
		write(1, "rra\n", 4);
}

void rrb(t_stack **b, int print)
{
	t_stack *b_lst;

	if (!b || !*b)
		return ;
	if (lst_size(*b) == 1)
		return ;
	b_lst = (*b);
	while (b_lst->next->next)
		b_lst = b_lst->next;
	b_lst->next->next = (*b);
	(*b) = b_lst->next;
	b_lst->next = NULL;
	
	if (print)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b)
{
	rra(a, 0);
	rrb(b, 0);
	write(1, "rrr\n", 4);
}
