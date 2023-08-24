#include "monty.h"


/**
 * pint_func - prints the value at the top of the stack
 * @head: Double linked list data structure
 * @line_number: File line number when reading
 */
void pint_func(stack_t **head, unsigned int line_number)
{
	if (!*head)
	{
		pint_err(line_number);

		free_alloc_memory();

		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*head)->n);
}


/**
 * pall_func - prints all the values on the stack, starting
 * from the top of the stack.
 * @head: Double linked list data struct
 * @line_number: File line number when reading
 */
void pall_func(stack_t **head, unsigned int line_number)
{
	stack_t *node_check = *head;

	(void) line_number;

	if (!node_check)
		return;

	while (node_check)
	{
		printf("%d\n", node_check->n);

		node_check = node_check->next;
	}
}
