#include "monty.h"

/**
 * stack_func - sets the format of the data to a stack (LIFO)
 * @head: Double linked list data struct
 * @line_number: File line number when reading
 */
void stack_func(stack_t **head, unsigned int line_number)
{
	(void) line_number;
	(void) head;

	glob_data.FORMAT = 0;
}

/**
 * queue_func - sets the format of the data to a queue (FIFO)
 * @head: Double linked list data struct
 * @line_number: File line number when reading
 */
void queue_func(stack_t **head, unsigned int line_number)
{
	(void) line_number;
	(void) head;

	glob_data.FORMAT = 1;
}
