#include "monty.h"


/**
 * push_func - pushes an element to the stack.
 * @head: Double linked list data structure
 * @line_number: File line number when reading
 */
void push_func(stack_t **head, unsigned int line_number)
{
	stack_t *new_elem = NULL;
	stack_t *node_check = *head;
	char *token;

	token = strtok(NULL, " \r\t\n");
	if (token == NULL || (is_strint_int(token) != 0 && token[0] != '-'))
	{
		push_error(line_number);
		free_alloc_memory();
		exit(EXIT_FAILURE);
	}
	new_elem = malloc(sizeof(stack_t));
	if (!new_elem)
	{
		malloc_err();
		free_alloc_memory();
		exit(EXIT_FAILURE);
	}
	new_elem->n = atoi(token);
	if (glob_data.FORMAT == 0 || !*head)
	{
		new_elem->next = *head;
		/* *head = new_elem; */
		new_elem->prev = NULL;
		if (*head)
			(*head)->prev = new_elem;
		*head = new_elem;
	}
	else
	{
		while (node_check->next)
			node_check = node_check->next;

		node_check->next = new_elem;
		new_elem->prev = node_check;

		new_elem->next = NULL;
	}
}
