
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>

struct s_node {
	int val;
	struct s_node *next;
};

typedef struct s_node t_node;

t_node *lst_new(void);
#endif
