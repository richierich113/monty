#include "monty.h"

/**
 * swap - swaps the top two elements of the stack.
 * @head: Double linked list data struct head
 * @line_number: File line number when reading
 */
void swap(stack_t **head, unsigned int line_number)
{
	int tmp;

	if (!*head || !(*head)->next)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n",
			line_number);

		free_all();

		exit(EXIT_FAILURE);
	}

	tmp = (*head)->n;
	(*head)->n = (*head)->next->n;

	(*head)->next->n = tmp;
}

/**
 * add - add the top two elements of the stack
 * @stack: Double linked list
 * @line_number: File line execution
 */
void add(stack_t **stack, unsigned int line_number)
{
	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n",
			line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (*stack)->next->n + (*stack)->n;
	pop(stack, line_number);
}

/**
 * sub - substract the top two elements of the stack
 * @stack: Double linked list
 * @line_number: Line counter
 */
void sub(stack_t **stack, unsigned int line_number)
{
	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n",
			line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (*stack)->next->n - (*stack)->n;
	pop(stack, line_number);
}

/**
 * divi - divide the top two elements of the stack
 * @stack: Double linked list
 * @line_number: File line counter
 */
void divi(stack_t **stack, unsigned int line_number)
{
	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n",
			line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (*stack)->next->n / (*stack)->n;
	pop(stack, line_number);
}
