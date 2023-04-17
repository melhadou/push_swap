#include "push_swap.h"

int main(int argc, char *argv[])
{
	t_node *node;

	node = lst_new();
	node->next = lst_new();
	node->next->next = lst_new();
	node->next->next->next = lst_new();

	node->val = 1;
	node->next->val = 2;
	node->next->next->val = 3;
	node->next->next->next->val = 4;
	if (argc == 1)
	{
		printf("enter some values");
		return (0);
	}
	else
	{
		printf("val -> %d",node->val);
		printf("val -> %d\n",node->next->val);
		printf("val -> %d\n",node->next->next->val);
		printf("val -> %d\n",node->next->next->next->val);
	}

	return (0);
}
