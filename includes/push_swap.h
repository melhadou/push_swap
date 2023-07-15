/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhadou <melhadou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 16:12:41 by melhadou          #+#    #+#             */
/*   Updated: 2023/07/15 11:16:02 by melhadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libs/libft/libft.h"
# include "../libs/getnextline/get_next_line.h"
# define CHUNK_SIZE 25

// stack struct
typedef struct t_stack {
	int				val;
	int				rank;
	struct t_stack	*next;
}	t_stack;

/* ***************		Linked List Function ***************** */

t_stack	*lst_new(void);
t_stack	*lst_last_node(t_stack *lst);
void	lst_add_back(t_stack **lst, t_stack *new);
int		lst_size(t_stack *lst);
void	lst_free(t_stack **stack);

/* ***************		Error Function ************************ */

void	ft_error(void);

/* ***************		Sorting Functions ********************* */

int		find_max(t_stack *a);
void	set_rank(t_stack *a);
int		check_doubles(t_stack *head);

/* ***************	 Other Sorting Functions **************** */

void	send_range(int start, int end, t_stack **a, t_stack **b);
void	send_all(t_stack **a, t_stack **b);
void	return_to_a_helper(t_stack **a, t_stack **b, int size_b);
void	return_to_a(t_stack **a, t_stack **b);

/* ***************		Sort four Functions ******************** */

void	sort_four(t_stack **a, t_stack **b);
void	push_smallest(t_stack **a, t_stack **b);

/* ***************		Sort three Functions ****************** */

void	sort_three(t_stack **a);

/* ***************		Sort five Functions ****************** */

void	sort_five(t_stack **a, t_stack **b);

/* ***************		Ft_free Functions ******************** */

void	ft_free_stack(t_stack **stack);
void	ft_free_string(char **str);

/* ***************		Helper Functions ********************* */

void	send_to_top(int pos, t_stack **b);
void	send_to_tail(int pos, t_stack **b);
void	send_to_top_or_tail(int pos, t_stack **b);
int		nb_rank_position(t_stack *stack, int rank);
int		check_is_ranked(t_stack *a);

/* ***************		Tweaks Functions ********************** */

int		ft_new_atoi(const char *nptr);
size_t	dbl_str_len(char **arr);
void	is_number(char *str);

/* ***************		Init Stak Functions ******************** */

void	init_stack(t_stack **a, char **argv);
char	**append_to_arr(char **arr, char *str);
char	**parse_argv(char **argv);
void	valid_args(char **args);

/* ***************		Push Instructions Functions ************* */

void	pb(t_stack **b, t_stack **a, int print);
void	pa(t_stack **a, t_stack **b, int print);

/* ************		Reverse Rotate Instructions Functions ******* */

void	rra(t_stack **a, int print);
void	rrb(t_stack **b, int print);
void	rrr(t_stack **a, t_stack **b);

/* *************		Rotate Instructions Functions ************** */

void	ra(t_stack **a, int print);
void	rb(t_stack **b, int print);
void	rr(t_stack **a, t_stack **b);

/* ***************		Swap Instructions Functions ************* */

void	sa(t_stack **a, int print);
void	sb(t_stack **b, int print);
void	ss(t_stack **a, t_stack **b);

/* ***************		Bonus Function ***************** */

void	apply_instruction(char *str, t_stack **a, t_stack **b);
int		check_is_sorted(t_stack *a);

#endif
