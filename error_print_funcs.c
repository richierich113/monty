#include "monty.h"

/**
 * argnum_error - Prints error message to stderr
 * when argument passed is not 2
 * @isfile_passed: boolean value parameter
 */
void argnum_error(bool isfile_passed)
{
	if (isfile_passed)
	{
		fprintf(stderr, "USAGE: monty file\n");
	}
}


/**
 * file_open_err - Prints error message to stderr
 * when argument file passed cannot open or grants
 * no read permission
 * @argv: argument file name passed
 */
void file_open_err(char *filename)
{
	fprintf(stderr, "Error: Can't open file %s\n", filename);
}
