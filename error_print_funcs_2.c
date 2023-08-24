#include "monty.h"


/**
 * swap_err - prints error message to stderr if the stack
 * contains less than two elements
 * @line_number: file line number when reading
 */
void swap_err(unsigned int line_number)
{
	fprintf(stderr, "L%u: can't swap, stack too short\n",
		line_number);
}

/**
 * add_stack_err - prints error message to stderr if the stack
 * contains less than two elements
 * @line_number: file line number when reading
 */
void add_stack_err(unsigned int line_number)
{
	fprintf(stderr, "L%u: can't add, stack too short\n",
		line_number);
}


/**
 * sub_err - prints error message to stderr if the stack
 * contains less than two elements
 * @line_number: file line number when reading
 */
void sub_err(unsigned int line_number)
{
	fprintf(stderr, "L%u: can't sub, stack too short\n",
		line_number);
}

/**
 * div_err -  prints error message to stderr if the stack
 * contains less than two elements
 * @line_number: file line number when reading
 */
void div_err(unsigned int line_number)
{
	fprintf(stderr, "L%u: can't div, stack too short\n",
		line_number);
}

/**
 * div_by_zero_err -  prints error message to stderr if the top
 * element of the stack is 0
 * @line_number: file line number when reading
 */
void div_by_zero_err(line_number)
{
	fprintf(stderr, "L%u: division by zero\n", line_number);
}
