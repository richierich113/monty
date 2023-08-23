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
	int arg_num = 2, check;

	if (argc < arg_num || argc > arg_num)
	{
		return (argnum_error());
	}
	check = start_vars(&var);
	if (check != 0)
		return (EXIT_FAILURE);
	var.file = fopen(argv[1], "r");
	if (!var.file)
	{
		file_open_err(argv[1]);
		/*fprintf(stderr, "Error: Can't open file %s\n", argv[1]);*/
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
