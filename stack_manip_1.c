#include "monty.h"

/**
 * add_func - adds the top two elements of the stack.
 * @head: Double linked list data struct head
 * @line_number: File line number when reading
 * Description: adds the top two elements of the stack and
 * store in the second top element of the stack.
 * The top element is removed, so that at the end:
 * The top element of the stack contains the result
 * The stack is one element shorter
 */
void add_func(stack_t **head, unsigned int line_number)
{
	if (!*head || !(*head)->next)
	{
		add_stack_err(line_number);

		free_all();
		exit(EXIT_FAILURE);
	}

	(*head)->next->n += (*head)->n;

	pop(head, line_number);
}

/**
 * div_func - divides the second top element of the stack
 * by the top element of the stack.
 * @head: Double linked list data struct head
 * @line_number: File line number when reading
 */
void div_func(stack_t **head, unsigned int line_number)
{
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

	(*head)->next->n /= (*head)->n;

	pop(head, line_number);
}


/**
 * swap_func - swaps the top two elements of the stack.
 * @head: Double linked list data struct head
 * @line_number: File line number when reading
 */
void swap_func(stack_t **head, unsigned int line_number)
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
 * sub_func - subtracts the top element of the stack from the second
 * top element of the stack.
 * @head: Double linked list data struct head
 * @line_number: File line number when reading
 * Description: subtracts the top element of the stack from the second
 * top element of the stack. Store in the second top element of the stack,
 * and the top element is removed, so that at the end:
 * The top element of the stack contains the result
 * The stack is one element shorter
 */
void sub_func(stack_t **head, unsigned int line_number)
{
	if (!*head || !(*head)->next)
	{
		sub_err(line_number);

		free_all();
		exit(EXIT_FAILURE);
	}

	(*head)->next->n -= (*head)->n;

	pop(head, line_number);
}
