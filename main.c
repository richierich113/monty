#include "monty.h"

vars var;

/**
 * main - the entry function to program
 * @argc: number of arguments passed to program parameter
 * @argv: pointer to array of arguments passed to program
 * parameter
 * Return: 0 on Success, otherwise 1
 */
int main(int argc, char **argv)
{
	char *opcode;
	bool isfile_passed = true
	int arg_count = 2;

	if (argc < arg_count || argc > arg_count)
	{
		isfile_passed = false
		argument_errprnt(isfile_passed);
		return (EXIT_FAILURE);
	}

	if (start_vars(&var) != 0)
		return (EXIT_FAILURE);

	var.file = fopen(av[1], "r");
	if (!var.file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		free_all();
		return (EXIT_FAILURE);
	}

	while (getline(&var.buff, &var.tmp, var.file) != EOF)
	{
		opcode = strtok(var.buff, " \r\t\n");
		if (opcode != NULL)
			if (call_funct(&var, opcode) == EXIT_FAILURE)
			{
				free_all();
				return (EXIT_FAILURE);
			}
		var.line_number++;
	}

	free_all();

	return (EXIT_SUCCESS);
}
