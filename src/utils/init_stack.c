/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhadou <melhadou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 11:52:44 by melhadou          #+#    #+#             */
/*   Updated: 2023/07/13 21:28:23 by melhadou         ###   ########.fr       */
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
		tmp->val = ft_new_atoi(args[i]);
		lst_add_back(a, tmp);
		i++;
	}

	ft_free_string(args);
	if (check_doubles(*a))
		ft_error();
	set_rank(*a);
}

static size_t	dbl_str_len(char **arr)
{
	size_t	len;

	len = 0;
	while (arr[len])
		len++;
	return (len);
}

char	**append_to_arr(char **arr, char *str)
{
	char	**res;
	size_t	i;

	i = 0;
	res = NULL;
	if (!arr)
	{
		arr = malloc(sizeof(char *));
		if (!arr)
			return (NULL);
		*arr = NULL;
	}
	res = malloc((dbl_str_len(arr) + 2) * sizeof(char *));
	if (!res)
		return (NULL);
	while (arr[i])
	{
		res[i] = ft_strdup(arr[i]);
		i++;
	}
	res[i] = str;
	res[i + 1] = NULL;
	ft_free_string(arr);
	return (res);
}

char	**parse_argv(char **argv)
{
	int i;
	int j;
	char **list;
	char **splits;

	i = 1;
	list = NULL;
	while (argv[i])
	{
		if (ft_strrchr(argv[i], ' '))
		{
			splits = ft_split(argv[i], ' ');
			j = 0;
			while (splits[j])
			{
				list = append_to_arr(list, ft_strdup(splits[j]));
				j++;
			}
			ft_free_string(splits);
		} else
			list = append_to_arr(list, ft_strdup(argv[i]));
		i++;
	}
	return (list);
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
