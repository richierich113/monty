#include "monty.h"


/**
 * start_global_glob_data_struct - initialize the global vars in struct
 * @glob_data: the variables in struct to initialize
 * Return: 0 on Successful initialization, otherwise 1
 */
int start_global_glob_data_struct(global_glob_data_struct *glob_data)
{
	glob_data->mext_file = NULL;

	glob_data->tmp = 0;

	glob_data->buff = NULL;

	glob_data->dict = new_dict_func();

	if (glob_data->dict == NULL)
		return (EXIT_FAILURE);

	glob_data->head = NULL;
	glob_data->line_number = 1;
	glob_data->MODE = 0;

	return (EXIT_SUCCESS);
}
