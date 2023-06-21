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
			return 1;
		}

		tmp = make_lst_copy(&a);
		bubble_sort_lst(&tmp);
		copy_rank(tmp, a);
		int phase = 0;
			first_phase(&a,&b, phase);
		printf("lst_size(a): %d\n",lst_size(a));
		ft_print_stacks(a, b);
	}
	return (0);
}
