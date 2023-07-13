/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhadou <melhadou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 11:32:08 by melhadou          #+#    #+#             */
/*   Updated: 2023/07/12 21:09:28 by melhadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char *argv[])
{
	t_stack *a;
	t_stack *b;

	a = NULL; // Initialize a to NULL
	b = NULL; // Initialize b to NULL
	if (argc == 1)
		return (0);

	init_stack(&a, argv);
	// check number if there are sorted
	sort_three(&a);
	// if (check_is_ranked(a))
	// 	send_all(&a, &b);
	// else
	// {
	// 	exit(1);
	// }
	ft_print_stacks(a, b);
	ft_free_stack(&a);
	ft_free_stack(&b);

	system("leaks push_swap");
	return (0);
}
