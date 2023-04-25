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

void	bubble_sort_lst(t_stack **head)
{
	t_stack	*tmp;
	t_stack	*current;
	int tmp_val;

	tmp = *head;
	current = *head;

	while (current)
	{
		tmp = current->next;
		while (tmp)
		{
			if (tmp->val < current->val)
			{
				tmp_val = current->val;
				current->val = tmp->val;
				tmp->val = tmp_val;
			}
			tmp = tmp->next;
		}
		current = current->next;
	}
}

int	check_doubles(t_stack **head)
{
	t_stack	*tmp;
	t_stack	*current;

	tmp = *head;
	current = *head;

	while (current)
	{
		tmp = current->next;
		while (tmp)
		{
			if (tmp->val == current->val)
			{
				return 1;
			}
			tmp = tmp->next;
		}
		current = current->next;
	}

	return 0;
}
