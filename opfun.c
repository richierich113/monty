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
 * push - Insert a new value in list
 * @stack: Double linked list
 * @line_number: File line execution
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = NULL, *tm = *stack;
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
	if (glob_data.MODE == 0 || !*stack)
	{
		tmp->next = *stack;
		tmp->prev = NULL;
		if (*stack)
			(*stack)->prev = tmp;
		*stack = tmp;
	}
	else
	{
		while (tm->next)
			tm = tm->next;
		tm->next = tmp;
		tmp->prev = tm;
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
