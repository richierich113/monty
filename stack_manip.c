#include "monty.h"

/**
 * mod - computes the rest of the division of the second top element of
 * the stack by the top element of the stack.
 * @head: top node of stack Double linked list data structure
 * @line_number: File line number when reading
 */
void mod(stack_t **head, unsigned int line_number)
{
	int result;

	if (!*head || !(*head)->next)
	{
		modulus_err(line_number);

		free_all();

		exit(EXIT_FAILURE);
	}

	if ((*head)->n == 0)
	{
		div_by_zero_err(line_number);

		free_all();

		exit(EXIT_FAILURE);
	}

	result = (*head)->next->n % (*head)->n;
	(*head)->next->n = result;

	pop(head, line_number);
}


/**
 * pstr - prints the string starting at the top of the stack,
 * followed by a new line.
 * @head: top node of stack Double linked list data structure
 * @line_number: File line number when reading
 */
void pstr(stack_t **head, unsigned int line_number)
{
	stack_t *tmp = *head;
	(void) line_number;

	if (!head || !*head)
	{
		putchar('\n');
		return;
	}
	while (tmp)
	{
		if (tmp->n == 0)
			break;
		if (!isascii((tmp)->n))
			break;
		putchar(tmp->n);
		tmp = tmp->next;
	}
	putchar('\n');
}



/**
 * pchar - prints the char at the top of the stack, followed by a new line.
 * The integer stored at the top of the stack is treated as the ascii value
 * of the character to be printed
 * @head: top node of stack Double linked list data structure
 * @line_number: File line number when reading
 */
void pchar(stack_t **head, unsigned int line_number)
{
	if (!head || !*head)
	{
		print_char_err(line_number);

		free_all();
		exit(EXIT_FAILURE);
	}

	if (isascii((*head)->n))
	{
		printf("%c\n", (*head)->n);
		return;
	}

	printch_out_of_range_err(line_number);

	free_all();

	exit(EXIT_FAILURE);
}

/**
 * mul - multiplies the second top element of the stack
 * with the top element of the stack.
 * @head: top node of stack Double linked list data structure
 * @line_number: File line number when reading
 * Description: multiplies the second top element of the stack
 * with the top element of the stack.
 * The result is stored in the second top element of the stack,
 * and the top element is removed, so that at the end:
 * The top element of the stack contains the result
 * The stack is one element shorter
 */
void mul(stack_t **head, unsigned int line_number)
{
	int result;

	if (!*head || !(*head)->next)
	{
		multiply_err(line_number);

		free_all();

		exit(EXIT_FAILURE);
	}

	result = (*head)->next->n * (*head)->n;
	(*head)->next->n = result;

	pop(head, line_number);
}