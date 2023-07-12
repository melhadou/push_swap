/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhadou <melhadou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 11:52:44 by melhadou          #+#    #+#             */
/*   Updated: 2023/07/12 16:38:35 by melhadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

void	init_stack(t_stack **a,char **argv)
{
	int i;
	t_stack *tmp;
	char **args;

	i = 0;

	args = parse_argv(argv);
	valid_args(args);
	
	tmp = *a;
	while (args[i])
	{
		tmp = lst_new();
		// protect from < MAXINT vals
		check_overflow(args[i]);
		tmp->val = ft_atoi(args[i]);
		if (!a)
			a = &tmp;
		else
			lst_add_back(a, tmp);
		i++;
	}

	tmp = *a;
	if (check_doubles(tmp))
		ft_error();

	set_rank(*a);
}

static void check_valid(char *str)
{
	int i;
	int j;

	i = 0;
	j = 0;

	if (!str[i])
		ft_error();
	while(str[i])
	{
		if (str[i] != ' ' && str[i] != '\t')
			j = 1;
		i++;
	}
	if (!j)
		ft_error();
}

char	**parse_argv(char **argv)
{
	char	**args;
	char *tmp;
	char *tmp2;
	int i;

	if (!argv[1][0])
		ft_error();
	tmp = ft_strdup(argv[1]);
	i = 2;
	while (argv[i])
	{
		check_valid(argv[i]);
		tmp2 = tmp;
		tmp = ft_strjoin(tmp, " ");
		tmp = ft_strjoin(tmp, argv[i]);
		free(tmp2);
		i++;
	}
	args = ft_split(tmp, ' ');
	free(tmp);
	return (args);
}

static void	is_number(char *str)
{
	int	i;

	i = 0;
	if (!str[i])
		ft_error();
	if ((str[i] == '+' || str[i] == '-') && str[i+1] != '\0')
		i++;
	while(str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			ft_error();
		i++;
	}
}

void	valid_args(char **args)
{
	int i;

	i = 0;
	while (args[i])
	{
		is_number(args[i]);
		i++;
	}
}

void	check_overflow(char *str)
{
	int nb;
	char *nb_str;

	nb = ft_atoi(str);
	nb_str = ft_itoa(nb);

	if (ft_strncmp(nb_str, str, -1))
		ft_error();
}
