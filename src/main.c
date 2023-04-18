#include "push_swap.h"

int main(int argc, char *argv[])
{
	t_node *node;
	t_node *tmp;
	size_t i;

	i = 0;
	if (argc == 1)
	{
		printf("enter some values");
		return (0);
	}
	else
	{
		while (argv[i])
		{
			tmp = lst_new();
			tmp->val = ft_atoi(argv[i]);
			lst_add_back(&node, tmp);
			i++;
		}
		
		tmp = node;
		
		while (tmp->next)
		{
			printf("val --> %d\n", tmp->val);
			tmp = tmp->next;
		}
		printf("size >> %d\n",lst_size(node));
	}

	return (0);
}
