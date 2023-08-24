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

	while (node_check->next != NULL)
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
		fprintf(stderr, "Error: malloc failed\n");
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
 * pint - Print last node
  * @stack: Double linked list data structure
 * @line_number: File line number when reading
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (!*stack)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}


/**
* pop - Delete top of list
* @stack: Double linked list
* @line_number: File line execution
*/
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (!*stack)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}

	tmp = *stack;
	*stack = tmp->next;
	if (tmp->next)
		tmp->next->prev = NULL;
	free(tmp);
}
