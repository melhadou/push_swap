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

		tmp = a;
		if (check_doubles(&tmp))
		{
			write(2, "Error", 5);
			return (1);
		}

		tmp = make_lst_copy(&a);
		// sorting the list so we can rank it
		bubble_sort_lst(&tmp);
		// we copy ranks to the original list
		copy_rank(tmp, a);
		first_phase(&a,&b);
		ft_print_stacks(a, b);
		printf("\nlst_size(a): %d\n\n\n\n",lst_size(a));
	}
	return (0);
}
