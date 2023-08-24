#include "monty.h"

/**
 * stack - sets the format of the data to a stack (LIFO)
 * @head: Double linked list data struct
 * @line_number: File line number when reading
 */
void stack(stack_t **head, unsigned int line_number)
{
	(void) line_number;
	(void) head;

	glob_data.MODE = 0;
}

/**
 * queue - sets the format of the data to a queue (FIFO)
 * @head: Double linked list data struct
 * @line_number: File line number when reading
 */
void queue(stack_t **head, unsigned int line_number)
{
	(void) line_number;
	(void) head;

	glob_data.MODE = 1;
}
