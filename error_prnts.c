#include "monty.h"

/**
 * usage_error - Prints error message to stderr
 * when argement passed is not 2
 * Return: (EXIT_FAILURE) always.
 */
int usage_error(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	return (EXIT_FAILURE);
}
