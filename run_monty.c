#include "monty.h"

/**
 * start_global_glob_data_struct - initialize the global vars in struct
 * @glob_data: the variables in struct to initialize
 * Return: 0 on Successful initialization, otherwise 1
 */
int start_global_glob_data_struct(global_glob_data_struct *glob_data)
{
	glob_data->file = NULL;

	glob_data->tmp = 0;

	glob_data->buff = NULL;

	glob_data->dict = create_instru();

	if (glob_data->dict == NULL)
		return (EXIT_FAILURE);

	glob_data->head = NULL;
	glob_data->line_number = 1;
	glob_data->MODE = 0;

	return (EXIT_SUCCESS);
}

/**
 * create_instru - Creates a new functions dictionary
 * Return: pointer to the created dictionary
 */
instruction_t *create_instru()
{
	instruction_t *instruct_buf = malloc(sizeof(instruction_t) * 18);

	if (!instruct_buf)
	{
		malloc_err();
		return (NULL);
	}
	instruct_buf[0].opcode = "pall", instruct_buf[0].f = pall_func;
	instruct_buf[1].opcode = "push", instruct_buf[1].f = push_func;
	instruct_buf[2].opcode = "pint", instruct_buf[2].f = pint_func;
	instruct_buf[3].opcode = "pop", instruct_buf[3].f = pop_func;
	instruct_buf[4].opcode = "swap", instruct_buf[4].f = swap_func;
	instruct_buf[5].opcode = "add", instruct_buf[5].f = add_func;
	instruct_buf[6].opcode = "nop", instruct_buf[6].f = NULL;
	instruct_buf[7].opcode = "sub", instruct_buf[7].f = sub_func;
	instruct_buf[8].opcode = "div", instruct_buf[8].f = div_func;
	instruct_buf[9].opcode = "mul", instruct_buf[9].f = mul_func;
	instruct_buf[10].opcode = "mod", instruct_buf[10].f = mod_func;
	instruct_buf[11].opcode = "pchar", instruct_buf[11].f = pchar_func;
	instruct_buf[12].opcode = "pstr", instruct_buf[12].f = pstr_func;
	instruct_buf[13].opcode = "rotl", instruct_buf[13].f = rotl_func;
	instruct_buf[14].opcode = "rotr", instruct_buf[14].f = rotr_func;
	instruct_buf[15].opcode = "stack", instruct_buf[15].f = stack_func;
	instruct_buf[16].opcode = "queue", instruct_buf[16].f = queue_func;
	instruct_buf[17].opcode = NULL, instruct_buf[17].f = NULL;

	return (instruct_buf);
}

/**
 * call_funct - calls needed functions
 * @glob_data: data struct for global vars
 * @read_opcode: command in file to execute
 * Return: 0 on success, otherwise 1
 */
int call_funct(global_glob_data_struct *glob_data, char *read_opcode)
{
	int count = 0;

	while (glob_data->dict[count].opcode)
	{
		if (strcmp(read_opcode, glob_data->dict[count].opcode) == 0)
		{
			if (!glob_data->dict[count].f)
				return (EXIT_SUCCESS);
			glob_data->dict[count].f(&glob_data->head, glob_data->line_number);
			return (EXIT_SUCCESS);
		}
		count += 1;
	}
	if (strlen(read_opcode) != 0 && read_opcode[0] != '#')
	{
		unknown_instruc_err(glob_data->line_number, read_opcode);
		return (EXIT_FAILURE);
	}

	return (EXIT_SUCCESS);
}

/**
 * free_all - frees all allocated data stored in
 * glob_data data struct global variables
 */
void free_all(void)
{
	if (glob_data.buff != NULL)
		free(glob_data.buff);

	if (glob_data.file != NULL)
		fclose(glob_data.file);

	free(glob_data.dict);
	if (glob_data.head != NULL)
	{
		while (glob_data.head->next != NULL)
		{
			glob_data.head = glob_data.head->next;
			free(glob_data.head->prev);
		}

		free(glob_data.head);
	}
}

/**
 * _isdigit - checks if a string parameter is an integer
 * @opcode_arg: string to check if its an integer
 * Return: 0 for Success if integer, 1 otherwise
 */
int _isdigit(char *opcode_arg)
{
	int count = 0;

	while (opcode_arg[count])
	{
		if (opcode_arg[count] < 48 || opcode_arg[count] > 57)
			return (1);

		count++;
	}
	return (0);
}
