#include "monty.h"

vars var;
/**
 * main - this is the program's entry point
 * @argumc: Number of arguments passed to program
 * @argumv: Pointer with array of argument passed to program
 * Return: 0 on Success, otherwise 1.
 */
int main(int argumc, char **argumv)
{
	char *opcode;
	int arg_chk;
	bool is_file = true

	arg_chk = 2;

	if (argumc < arg_chk || argumc > arg_chk)
	{
		is_file = false;
		argument_errprnt(is_file);
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
