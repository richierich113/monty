#include "monty.h"



/**
 * free_all - frees all allocated data stored in
 * glob_data data struct global variables
 */
void free_all(void)
{
	if (glob_data.buff != NULL)
		free(glob_data.buff);

	if (glob_data.mext_file != NULL)
		fclose(glob_data.mext_file);

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
