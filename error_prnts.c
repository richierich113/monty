#include "monty.h"


int argnum_error(void);
/**
 * argnum_error - Prints error message to stderr
 * when argement passed is not 2
 * Return: (EXIT_FAILURE) always.
 */
int argnum_error(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	return (EXIT_FAILURE);
}
