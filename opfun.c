#include "monty.h"
/**
 * pall - prints all the values on the stack, starting from the top of the stack.
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
	stack_t *tmp = NULL, *node_check = *head;
	char *num;

	num = strtok(NULL, " \r\t\n");
	if (num == NULL || (_isdigit(num) != 0 && num[0] != '-'))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	tmp = malloc(sizeof(stack_t));
	if (!tmp)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_all();
		exit(EXIT_FAILURE);
	}
	tmp->n = atoi(num);
	if (glob_data.MODE == 0 || !*head)
	{
		tmp->next = *head;

		tmp->prev = NULL;
		if (*head)
			(*head)->prev = tmp;
		*head = tmp;
	}
	else
	{
		while (node_check->next)
			node_check = node_check->next;
		node_check->next = tmp;
		tmp->prev = node_check;
		tmp->next = NULL;
	}
}

/**
 * pint - Print last node
 * @stack: Double linked list
 * @line_number: File line execution
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
