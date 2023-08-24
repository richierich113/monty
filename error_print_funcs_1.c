#include "monty.h"

/**
 * pint_err - Prints error message to stderr
 * when stack is empty
 * @line_number: file line number when reading
 */
void pint_err(unsigned int line_number)
{
	fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
}


/**
 * pop_err - Prints error message to stderr when popping fails
 * due to empty stack
 * @line_number: file line number when reading
 */
void pop_err(unsigned int line_number)
{
	fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
}

/**
 * modulus_err - Prints error message to stderr
 * when stack is empty
 * @line_number: file line number when reading
 */
void modulus_err(unsigned int line_number)
{
	fprintf(stderr, "L%u: can't mod, stack too short\n",
		line_number);
}

/**
 * print_char_err - Prints error message to stderr
 * when stack is empty
 * @line_number: file line number when reading
 */
void print_char_err(unsigned int line_number)
{
	fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
}


/**
 * printch_out_of_range_err - Prints error message to stderr
 * If the value is not in the ascii table
 * @line_number: file line number when reading
 */
void printch_out_of_range_err(unsigned int line_number)
{
	fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
}
