/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhadou <melhadou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 08:12:23 by melhadou          #+#    #+#             */
/*   Updated: 2023/07/15 11:21:04 by melhadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	apply_instruction(char *str, t_stack **a, t_stack **b)
{
	if (!ft_strcmp(str, "sa"))
		sa(a, 0);
	else if (!ft_strcmp(str, "sb"))
		sb(b, 0);
	else if (!ft_strcmp(str, "ss"))
		ss(a, b);
	else if (!ft_strcmp(str, "pa"))
		pa(a, b, 0);
	else if (!ft_strcmp(str, "pb"))
		pb(b, a, 0);
	else if (!ft_strcmp(str, "ra"))
		ra(a, 0);
	else if (!ft_strcmp(str, "rb"))
		rb(a, 0);
	else if (!ft_strcmp(str, "rr"))
		rr(a, b);
	else if (!ft_strcmp(str, "rra"))
		rra(a, 0);
	else if (!ft_strcmp(str, "rrb"))
		rrb(a, 0);
	else if (!ft_strcmp(str, "rrr"))
		rrr(a, b);
	else
		ft_error();
}

int	check_is_sorted(t_stack *a)
{
	t_stack	*tmp;

	tmp = a;
	while (tmp->next)
	{
		if (tmp->val > tmp->next->val)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char	*str;

	a = NULL;
	b = NULL;
	if (ac == 1)
		return (0);
	init_stack(&a, av);
	str = get_next_line(0);
	while (1)
	{
		if (!str)
			break ;
		apply_instruction(str, &a, &b);
		free(str);
		str = get_next_line(0);
	}
	if (check_is_sorted(a) && !b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}
