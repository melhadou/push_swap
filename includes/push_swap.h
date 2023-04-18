
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#	include <stddef.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct t_node {
	int val;
	struct t_node *next;
} t_node;

t_node *lst_new(void);
t_node	*lst_last(t_node *lst);
void lst_add_back(t_node **lst, t_node *new);
int	ft_atoi(const char *nptr);
int	lst_size(t_node *lst);
#endif
