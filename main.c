#include "monty.h"

global_var_struct glob_data;

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
	check = start_vars(&glob_data);
	if (check != 0)
		return (EXIT_FAILURE);
	glob_data.file = fopen(argv[1], "r");
	if (!glob_data.file)
	{
		file_open_err(argv[1]);
		/*fprintf(stderr, "Error: Can't open file %s\n", argv[1]);*/
		free_all();
		return (EXIT_FAILURE);
	}
	while (getline(&glob_data.buff, &glob_data.tmp, glob_data.file) != -1)
	{
		opcode = strtok(glob_data.buff, " \r\t\n");
		if (opcode != NULL)
			if (call_funct(&glob_data, opcode) == EXIT_FAILURE)
			{
				free_all();
				return (EXIT_FAILURE);
			}
		glob_data.line_number++;
	}
	free_all();
	return (EXIT_SUCCESS);
}
