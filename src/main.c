/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhadou <melhadou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 11:32:08 by melhadou          #+#    #+#             */
/*   Updated: 2023/07/09 16:54:32 by melhadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char *argv[])
{
	t_stack *a;
	t_stack *b;
	t_stack *tmp;
	int size;
	size_t i;

	a = NULL; // Initialize a to NULL
	b = NULL; // Initialize b to NULL
	tmp = NULL; // Initialize tmp to NULL

	i = 1;
	if (argc == 1)
	{
		printf("enter some values");
		return (0);
	}
	else
	{
		while (argv[i])
		{
			tmp = lst_new();
			tmp->val = ft_atoi(argv[i]);
			if (!a)
				a = tmp;
			else
				lst_add_back(&a, tmp);
			i++;
		}

		tmp = a;
		if (check_doubles(tmp))
		{
			write(2, "Error\n", 6);
			exit(1);
		}

		set_rank(a);
		size = lst_size(a);
		// int	cost_a = nt_instruction(a, 80);
		// send_to_top_or_tail(cost_a, &a);
		send_all(&a, &b);
		// ft_print_stacks(a, b);
	}
	return (0);
}
