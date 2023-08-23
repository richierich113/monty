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
	char *opcode;
	int check, arg_num = 2;

	if (argc < arg_num || argc > arg_num)
	{
		return (argnum_error());
	}
	check = start_vars(&var);
	if (check != 0)
		return (EXIT_FAILURE);
	if (access(filename, R_OK) == 0)
	{
		var.file = fopen(argv[1], "r");
		if (!var.file)
		{
			file_open_err(argv[1]);
			free_all();
			return (EXIT_FAILURE);
		}
		while (getline(&var.buff, &var.tmp, var.file) != -1)
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
	else
	{
		file_open_err(argv[1]);
		return (EXIT_FAILURE);
}
