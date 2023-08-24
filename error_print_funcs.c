#include "monty.h"


/**
 * argnum_error - Prints error message to stderr
 * when argument passed is not 2
 * Return: EXIT_FAILURE
 */
int argnum_error(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	return (EXIT_FAILURE);
}


/**
 * file_open_err - Prints error message to stderr
 * when argument file passed cannot open or grants
 * no read permission
 * @filename: argument file name passed
 */
void file_open_err(const char *filename)
{
	fprintf(stderr, "Error: Can't open file %s\n", filename);
}


/**
 * malloc_err - Prints error message to stderr when malloc fails
 */
void malloc_err(void);
{
	fprintf(stderr, "Error: malloc failed\n");
}

/**
 * unknown_instruc_err - Prints error message to stderr
 * when instruction is unknown
 * @line_number: file line number when reading
 * @read_opcode: read command from file to execute
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
 * @line_number: file line number when reading
 */
void push_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: usage: push integer\n", line_number);
}
