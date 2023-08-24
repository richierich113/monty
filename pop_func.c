#include "monty.h"


/**
* pop_func - removes the top element of the stack updating the pointers
* of adjacent nodes and freeing the memory of the removed element
* @head: Doubly linked list data struct head
* @line_number: File line number when reading
*/
void pop_func(stack_t **head, unsigned int line_number)
{
	stack_t *top_node;

	if (!*head)
	{
		pop_err(line_number);

		free_alloc_memory();

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
