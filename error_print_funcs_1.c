#include "monty.h"

/**
 * pint_err - Prints error message to stderr
 * when stack is empty
 * @line_number: file line number when reading
 */
void pint_err(unsigned int line_number);
{
	fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
}


/**
 * pop_err - Prints error message to stderr when popping fails
 * due to empty stack
 */
void pop_err(unsigned int line_number);
{
	fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
}
