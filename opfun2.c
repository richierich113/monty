#include "monty.h"

/**
 * swap - swaps the top two elements of the stack.
 * @head: Double linked list data struct head
 * @line_number: File line number when reading
 */
void swap(stack_t **head, unsigned int line_number)
{
	int val_a;
	int val_b;

	if (!*head || !(*head)->next)
	{
		swap_err(line_number);

		free_all();

		exit(EXIT_FAILURE);
	}

	val_a = (*head)->n;
	val_b = (*head)->next->n;

	(*head)->n = val_b;
	(*head)->next->n = val_a;

}

/**
 * add - adds the top two elements of the stack.
 * @head: Double linked list data struct head
 * @line_number: File line number when reading
 * Description: adds the top two elements of the stack and
 * store in the second top element of the stack.
 * The top element is removed, so that at the end:
 * The top element of the stack contains the result
 * The stack is one element shorter
 */
void add(stack_t **head, unsigned int line_number)
{
	int = result;

	if (!*head || !(*head)->next)
	{
		add_stack_err(line_number);

		free_all();
		exit(EXIT_FAILURE);
	}

	result = (*head)->next->n + (*head)->n;
	(*head)->next->n  = result;

	pop(head, line_number);
}

/**
 * sub - subtracts the top element of the stack from the second
 * top element of the stack.
 * @head: Double linked list data struct head
 * @line_number: File line number when reading
 * Description: subtracts the top element of the stack from the second
 * top element of the stack. Store in the second top element of the stack,
 * and the top element is removed, so that at the end:
 * The top element of the stack contains the result
 * The stack is one element shorter
 */
void sub(stack_t **head, unsigned int line_number)
{
	int result;

	if (!*head || !(*head)->next)
	{
		sub_err(line_number);

		free_all();
		exit(EXIT_FAILURE);
	}

	result = (*head)->next->n - (*head)->n;
	(*head)->next->n = result;

	pop(head, line_number);
}

/**
 * divi - divides the second top element of the stack
 * by the top element of the stack.
 * @head: Double linked list data struct head
 * @line_number: File line number when reading
 */
void divi(stack_t **head, unsigned int line_number)
{
	int result;

	if (!*head || !(*head)->next)
	{
		div_err(line_number);

		free_all();

		exit(EXIT_FAILURE);
	}

	if ((*head)->n == 0)
	{
		div_by_zero_err(line_number);

		free_all();

		exit(EXIT_FAILURE);
	}

	result = (*head)->next->n / (*head)->n;
	(*head)->next->n = result;

	pop(head, line_number);
}
