#include "monty.h"


/**
 * argnum_error - Prints error message to stderr
 * when argument passed is not 2
 * Return: EXIT_FAILURE
 */
int argnum_error(void)
{
	fprintf(stderr, "USAGE: monty mext_file\n");
	return (EXIT_FAILURE);
}


/**
 * mext_file_open_err - Prints error message to stderr
 * when argument mext_file passed cannot open or grants
 * no read permission
 * @mext_filename: argument mext_file name passed
 */
void mext_file_open_err(const char *mext_filename)
{
	fprintf(stderr, "Error: Can't open mext_file %s\n", mext_filename);
}


/**
 * malloc_err - Prints error message to stderr when malloc fails
 */
void malloc_err(void)
{
	fprintf(stderr, "Error: malloc failed\n");
}

/**
 * unknown_instruc_err - Prints error message to stderr
 * when instruction is unknown
 * @line_number: mext_file line number when reading
 * @read_opcode: read command from mext_file to execute
 * unknown_instruc_err(glob_data->line_number, opcode)
 */
void unknown_instruc_err(unsigned int line_number,
	char *read_opcode)
{
	fprintf(stderr, "L%u: unknown instruction %s\n",
		line_number, read_opcode);
}


/**
 * push_error - Prints error message to stderr
 * when instruction is unknown
 * @line_number: mext_file line number when reading
 */
void push_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: usage: push integer\n", line_number);
}
