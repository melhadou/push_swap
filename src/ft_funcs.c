/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_funcs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhadou <melhadou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 11:32:18 by melhadou          #+#    #+#             */
/*   Updated: 2023/07/08 11:32:32 by melhadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_neg(int s)
{
	if (s == 1)
		return (-1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	unsigned long long	n;
	int					i;
	int					sign;

	n = 0;
	i = 0;
	sign = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
		sign = 1 - 2 * (nptr[i++] == '-');
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		n = n * 10 + (nptr[i] - '0');
		if (n > 9223372036854775807)
			return (is_neg(sign));
		i++;
	}
	return (n * sign);
}

void	ft_print_stacks(t_stack *a, t_stack *b)
{
	while (a || b)
	{
		if (a)
		{
			printf("a: %d\t a->rank: %d\t| ",a->val,a->rank);
			a = a->next;
		}
		if (b)
		{
			printf("b: %d\t b->rank: %d\t| ",b->val, b->rank);
			b = b->next;
		}
		printf("\n");
	}
}
