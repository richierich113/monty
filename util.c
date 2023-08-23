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
 * create_instru - Create new functions dictionary
 * Return: Dictionary pointer
 */
instruction_t *create_instru()
{
	instruction_t *instruct_buf = malloc(sizeof(instruction_t) * 18);

	if (!instruct_buf)
	{
		fprintf(stderr, "Error: malloc failed\n");
		return (NULL);
	}
	instruct_buf[0].opcode = "pall", instruct_buf[0].f = pall;
	instruct_buf[1].opcode = "push", instruct_buf[1].f = push;
	instruct_buf[2].opcode = "pint", instruct_buf[2].f = pint;
	instruct_buf[3].opcode = "pop", instruct_buf[3].f = pop;
	instruct_buf[4].opcode = "swap", instruct_buf[4].f = swap;
	instruct_buf[5].opcode = "add", instruct_buf[5].f = add;
	instruct_buf[6].opcode = "nop", instruct_buf[6].f = NULL;
	instruct_buf[7].opcode = "sub", instruct_buf[7].f = sub;
	instruct_buf[8].opcode = "div", instruct_buf[8].f = divi;
	instruct_buf[9].opcode = "mul", instruct_buf[9].f = mul;
	instruct_buf[10].opcode = "mod", instruct_buf[10].f = mod;
	instruct_buf[11].opcode = "pchar", instruct_buf[11].f = pchar;
	instruct_buf[12].opcode = "pstr", instruct_buf[12].f = pstr;
	instruct_buf[13].opcode = "rotl", instruct_buf[13].f = rotl;
	instruct_buf[14].opcode = "rotr", instruct_buf[14].f = rotr;
	instruct_buf[15].opcode = "stack", instruct_buf[15].f = stack;
	instruct_buf[16].opcode = "queue", instruct_buf[16].f = queue;
	instruct_buf[17].opcode = NULL, instruct_buf[17].f = NULL;

	return (instruct_buf);
}

/**
 * call_funct - Call Functions
 * @glob_data: Global glob_dataiables
 * @opcode: Command to execute
 * Return: None
 */
int call_funct(global_glob_data_struct *glob_data, char *opcode)
{
	int i = 0;

	while (glob_data->dict[i].opcode)
	{
		if (strcmp(opcode, glob_data->dict[i].opcode) == 0)
		{
			if (!glob_data->dict[i].f)
				return (EXIT_SUCCESS);
			glob_data->dict[i].f(&glob_data->head, glob_data->line_number);
			return (EXIT_SUCCESS);
		}
		i++;
	}
	if (strlen(opcode) != 0 && opcode[0] != '#')
	{
		fprintf(stderr, "L%u: unknown instruction %s\n",
			glob_data->line_number, opcode);
		return (EXIT_FAILURE);
	}

	return (EXIT_SUCCESS);
}

/**
 * free_all - Clean all program mallocs
 * Return: None
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
 * _isdigit - Clean all program mallocs
 * @string: Num to validate
 * Return: 0 Success, 1 Failed
 */
int _isdigit(char *string)
{
	int i;

	for (i = 0; string[i]; i++)
	{
		if (string[i] < 48 || string[i] > 57)
			return (1);
	}
	return (0);
}
