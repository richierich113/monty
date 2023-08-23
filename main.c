#include "monty.h"

vars var;

/**
 * main - Start LIFO, FILO program
 * @argc: Number of arguments
 * @argv: Pointer containing arguments
 * Return: 0 Success, 1 Failed
 */
int main(int argc, char **argv)
{
	char *opcode_var;

	if (argc < 2 || argc > 2)
	{
		return (argnum_error());
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
		opcode_var = strtok(var.buff, " \r\t\n");
		if (opcode_var != NULL)
			if (call_funct(&var, opcode_var) == EXIT_FAILURE)
			{
				free_all();
				return (EXIT_FAILURE);
			}
		var.line_number++;
	}

	free_all();

	return (EXIT_SUCCESS);
}
