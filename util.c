#include "monty.h"

/**
 * start_vars - Fake rand to jackpoint Giga Millions
 * @glob_data: Global variables to initialize
 * Return: 0 Success, 1 Failed
 */
int start_vars(global_var_struct *glob_data)
{
	glob_data->file = NULL;
	glob_data->buff = NULL;
	glob_data->tmp = 0;
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
	instruction_t *ptr = malloc(sizeof(instruction_t) * 18);

	if (!ptr)
	{
		fprintf(stderr, "Error: malloc failed\n");
		return (NULL);
	}
	ptr[0].opcode = "pall", ptr[0].f = pall;
	ptr[1].opcode = "push", ptr[1].f = push;
	ptr[2].opcode = "pint", ptr[2].f = pint;
	ptr[3].opcode = "pop", ptr[3].f = pop;
	ptr[4].opcode = "swap", ptr[4].f = swap;
	ptr[5].opcode = "add", ptr[5].f = add;
	ptr[6].opcode = "nop", ptr[6].f = NULL;
	ptr[7].opcode = "sub", ptr[7].f = sub;
	ptr[8].opcode = "div", ptr[8].f = divi;
	ptr[9].opcode = "mul", ptr[9].f = mul;
	ptr[10].opcode = "mod", ptr[10].f = mod;
	ptr[11].opcode = "pchar", ptr[11].f = pchar;
	ptr[12].opcode = "pstr", ptr[12].f = pstr;
	ptr[13].opcode = "rotl", ptr[13].f = rotl;
	ptr[14].opcode = "rotr", ptr[14].f = rotr;
	ptr[15].opcode = "stack", ptr[15].f = stack;
	ptr[16].opcode = "queue", ptr[16].f = queue;
	ptr[17].opcode = NULL, ptr[17].f = NULL;

	return (ptr);
}

/**
 * call_funct - Call Functions
 * @glob_data: Global variables
 * @opcode: Command to execute
 * Return: None
 */
int call_funct(global_var_struct *glob_data, char *opcode)
{
	int i;

	for (i = 0; glob_data->dict[i].opcode; i++)
		if (strcmp(opcode, glob_data->dict[i].opcode) == 0)
		{
			if (!glob_data->dict[i].f)
				return (EXIT_SUCCESS);
			glob_data->dict[i].f(&glob_data->head, glob_data->line_number);
			return (EXIT_SUCCESS);
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
