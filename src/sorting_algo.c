#include "push_swap.h"

t_stack *make_lst_copy(t_stack **lst) {
	t_stack *copy;
	t_stack *current;
	t_stack *tmp;

	if (!lst)
		return NULL;
	copy = NULL;
	current = *lst;
	while (current)
	{
		tmp = lst_new();
		tmp->val = current->val;
		tmp->next = NULL;
		if (!copy)
			copy = tmp;
		else
			lst_add_back(&copy, tmp);
		current = current->next;
	}
	return copy;
}
