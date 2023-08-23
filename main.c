#include "monty.h"

global_glob_data_struct glob_data;

/**
 * main - the entry function to program
 * @argc: number of arguments passed to program parameter
 * @argv: pointer to array of arguments passed to program
 * parameter
 * Return: 0 on Success, otherwise 1
 */
int main(int argc, char **argv)
{
	char *opcode_tok;
	int arg_num = 2, check, err_check;

	if (argc < arg_num || argc > arg_num)
	{
		return (argnum_error());
	}
	check = start_global_glob_data_struct(&glob_data);
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
	for (glob_data.line_number = 1; getline(&glob_data.buff, &glob_data.tmp,
		glob_data.file) != -1; glob_data.line_number++)
	{
		opcode_tok = strtok(glob_data.buff, " \r\t\n");
		if (opcode_tok != NULL)
			err_check = call_funct(&glob_data, opcode_tok);
			if (err_check == EXIT_FAILURE)
			{
				free_all();
				return (EXIT_FAILURE);
			}
	}
	free_all();
	return (EXIT_SUCCESS);
}
