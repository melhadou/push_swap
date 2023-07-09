#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#	include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# define CHUNK_SIZE 5

// stack struct
typedef struct	t_stack {
	int	val;
	int rank;
	struct t_stack	*next;
} t_stack;

/******* t_chunks ******
	* start - start index of chunk
	* end - end index of chunk
	* size - total size of chunks
*/

// chunks struct
typedef struct t_chunks {
	int start;
	int end;
	int size;
} t_chunks;

// lists funcs
t_stack	*lst_new(void);
t_stack	*lst_last_node(t_stack *lst);
void	lst_add_back(t_stack **lst, t_stack *new);
void lst_free(t_stack **stack);
int	lst_size(t_stack *lst);

// libft funcs
int	ft_atoi(const char *nptr);

// for debug
void	ft_print_stacks(t_stack *a, t_stack *b);

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
// t_stack	*make_lst_copy(t_stack **lst);
// void	bubble_sort_lst(t_stack **head);
int	check_doubles(t_stack *head);
// t_stack	*set_rank(t_stack **head, t_stack **sorted);
// void copy_rank(t_stack *head1, t_stack *head2);

// chunks
t_chunks	*find_chunks(t_stack **a);
int	find_from_top(t_stack *a, t_chunks chunk);
int	find_from_tail(t_stack *a, t_chunks chunk);
void	send_to_top(int pos, t_stack **a);
void	send_to_tail(int pos, t_stack **a);

void	first_phase(t_stack **a);
int	find_max(t_stack *a);
void	set_rank(t_stack *a);
int	nt_instruction(t_stack *a, int rank); 
void	send_to_top_or_tail(int pos, t_stack **a);
void	send_range(int start, int end, t_stack **a, t_stack **b);
void	send_all(t_stack **a, t_stack **b);
#endif
