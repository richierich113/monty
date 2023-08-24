#include "monty.h"
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
 * push - pushes an element to the stack.
 * @head: Double linked list data structure
 * @line_number: File line number when reading
 */
void push(stack_t **head, unsigned int line_number)
{
	stack_t *new_elem = NULL;
	stack_t *node_check = *head;
	char *num;

	num = strtok(NULL, " \r\t\n");
	if (num == NULL || (_isdigit(num) != 0 && num[0] != '-'))
	{
		push_error(line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	new_elem = malloc(sizeof(stack_t));
	if (!new_elem)
	{
		malloc_err();
		free_all();
		exit(EXIT_FAILURE);
	}
	new_elem->n = atoi(num);
	if (glob_data.MODE == 0 || !*head)
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

	*head = (*head)->next;
	top_node = *head;
	top_node->prev = NULL;

	if (top_node->next != NULL)
		top_node->next->prev = top_node;

	free(*head);
}
