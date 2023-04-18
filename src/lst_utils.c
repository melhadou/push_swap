#include "push_swap.h"

t_node *lst_new(void)
{
	t_node *tmp;
	tmp = malloc(sizeof(t_node));
	tmp->val = 0;
	tmp->next = NULL;
	return tmp;
}

t_node	*lst_last(t_node *lst)
{
	t_node	*tmp;

	if (!lst)
		return (NULL);
	tmp = lst;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

void lst_add_back(t_node **lst, t_node *new)
{
	t_node	*tmp;

	if (!lst || !new)
		return ;
	else if (!*lst)
		*lst = new;
	else
	{
		tmp = lst_last(*lst);
		tmp->next = new;
	}
}

int	lst_size(t_node *lst)
{
	t_node *tmp;
	size_t	i;

	i = 0;
	tmp = lst;
	while (tmp->next)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}
