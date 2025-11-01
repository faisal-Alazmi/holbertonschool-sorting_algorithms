cat > 1-main.c << 'EOF'
#include "sort.h"

/* helper: create a doubly linked list from array */
static listint_t *create_listint(const int *array, size_t size)
{
	listint_t *head = NULL, *node = NULL, *tmp;
	size_t i;

	for (i = 0; i < size; i++)
	{
	tmp = malloc(sizeof(*tmp));
	if (!tmp)
	return (NULL);
	/* note: project typedef uses 'const int n' */
	*(int *)&tmp->n = array[i];
	tmp->prev = node;
	tmp->next = NULL;
	if (node)
	node->next = tmp;
	else
	head = tmp;
	node = tmp;
	}
	return (head);
}

int main(void)
{
	listint_t *list;
	int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
	size_t n = sizeof(array) / sizeof(array[0]);

	list = create_listint(array, n);
	if (!list)
	return (1);

	print_list(list);
	printf("\n");

	insertion_sort_list(&list);
	printf("\n");

	print_list(list);
	return (0);
}
EOF
