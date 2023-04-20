#include "push_swap.h"

int main(int argc, char *argv[])
{
	t_stack *a;
	t_stack *b;
	t_stack *tmp;
	size_t i;

	a = NULL; // Initialize a to NULL
	b = NULL; // Initialize b to NULL
	tmp = NULL; // Initialize tmp to NULL

	i = 1;
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
			tmp->rank = i;
			if (!a)
				a = tmp;
			else
				lst_add_back(&a, tmp);
			i++;
		}

		
		printf("size a >> %d,\n\n", lst_size(a));
		tmp = a;
		while (tmp)
		{
			printf("val --> %d\t rank --> %d\n", tmp->val,tmp->rank);
			tmp = tmp->next;
		}

		// rra(&a, 1);
		rra(&a, 1);

		printf("\nsize a >> %d,\n\n", lst_size(a));
		tmp = a;
		while (tmp)
		{
			printf("val --> %d\t rank --> %d\n", tmp->val,tmp->rank);
			tmp = tmp->next;
		}

		tmp = b;
		printf("\nsize b >> %d,\n\n", lst_size(b));
		while (tmp)
		{
			printf("val --> %d\t rank --> %d\n", tmp->val,tmp->rank);
			tmp = tmp->next;
		}
	}
	return (0);
}
