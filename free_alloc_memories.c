#include "monty.h"



/**
 * free_alloc_memory - frees all allocated data stored in
 * glob_data data struct global variables
 */
void free_alloc_memory(void)
{
	if (glob_data.read_buffer != NULL)
		free(glob_data.read_buffer);

	if (glob_data.mext_file != NULL)
		fclose(glob_data.mext_file);

	free(glob_data.instruc_dict);
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
