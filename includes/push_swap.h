
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#	include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

// stack struct
typedef struct	t_stack {
	int	val;
	int rank;
	struct t_stack	*next;
} t_stack;

// lists funcs
t_stack	*lst_new(void);
t_stack	*lst_last_node(t_stack *lst);
void	lst_add_back(t_stack **lst, t_stack *new);
void lst_free(t_stack **stack);
int	lst_size(t_stack *lst);

// libft funcs
int	ft_atoi(const char *nptr);

// algo funcs
void	sa(t_stack **a, int print);
void	sb(t_stack **b, int print);
void	ss(t_stack **a, t_stack **b);
void	pb(t_stack **b, t_stack **a, int print);
void	pa(t_stack **a, t_stack **b, int print);
void	ra(t_stack **a, int print);
void	rb(t_stack **b, int print);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a, int print);
void	rrb(t_stack **b, int print);
void	rrr(t_stack **a, t_stack **b);

// sorting funcs
t_stack	*make_lst_copy(t_stack **lst);
void	bubble_sort_lst(t_stack **head);
int	check_doubles(t_stack **head);
#endif
