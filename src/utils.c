#include "push_swap.h"

t_node *lst_new(void)
{
	t_node *tmp;
	tmp = malloc(sizeof(t_node));
	tmp->val = 0;
	tmp->next = NULL;
	return tmp;
}
