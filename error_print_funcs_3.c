#include "monty.h"


/**
 * multiply_err - Prints error message to stderr
 * when stack is empty
 * @line_number: mext_file line number when reading
 */
void multiply_err(unsigned int line_number)
{
	fprintf(stderr, "L%u: can't mul, stack too short\n",
		line_number);
}
