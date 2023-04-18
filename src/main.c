#include "push_swap.h"

int main(int argc, char *argv[])
{
	t_node *node;
	t_node *tmp;
	size_t i;

	node = NULL; // Initialize node to NULL
	tmp = NULL; // Initialize tmp to NULL
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
			if (!node)
				node = tmp;
			else
				lst_add_back(&node, tmp);
			i++;
		}
	
		while (node)
		{
			printf("val --> %d\n", node->val);
			node = node->next;
		}
		printf("size >> %d\n", lst_size(node));
	}

	return (0);
}
