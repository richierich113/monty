#include "monty.h"


/**
 * pint - prints the value at the top of the stack
 * @head: Double linked list data structure
 * @line_number: File line number when reading
 */
void pint(stack_t **head, unsigned int line_number)
{
	if (!*head)
	{
		pint_err(line_number);

		free_all();

		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*head)->n);
}


/**
 * pall - prints all the values on the stack, starting
 * from the top of the stack.
 * @head: Double linked list data struct
 * @line_number: File line number when reading
 */
void pall(stack_t **head, unsigned int line_number)
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



/**
* pop - removes the top element of the stack updating the pointers
* of adjacent nodes and freeing the memory of the removed element
* @head: Doubly linked list data struct head
* @line_number: File line number when reading
*/
void pop(stack_t **head, unsigned int line_number)
{
	stack_t *top_node;

	if (!*head)
	{
		pop_err(line_number);

		free_all();

		exit(EXIT_FAILURE);
	}

	top_node = *head;
	*head = top_node->next;

	if (top_node->next)
	{
		top_node->next->prev = NULL;
	}

	free(top_node);
}
