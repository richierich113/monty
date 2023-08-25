#include "monty.h"


/**
 * rotr_func -  rotates the stack to the bottom.
 * @head: Double linked list data struct
 * @line_number: File line number when reading
 */
void rotr_func(stack_t **head, unsigned int line_number)
{
	stack_t *tmp_node;

	(void) line_number;

	if (!*head || !(*head)->next)
		return;

	tmp_node = *head;

	for (; tmp_node->next; tmp_node = tmp_node->next);

	tmp_node->next = *head;

	tmp_node->prev->next = NULL;
	tmp_node->prev = NULL;

	(*head)->prev = tmp_node;

	*head = tmp_node;

}


/**
 * rotl_func - rotates the stack to the top.
 * @head: Double linked list data struct
 * @line_number: File line number when reading
 */
void rotl_func(stack_t **head, unsigned int line_number)
{
	stack_t *tmp_node = *head;
	(void) line_number;

	if (!*head || !(*head)->next)
		return;

	(*head)->next->prev = NULL;

	for (; tmp_node->next; tmp_node = tmp_node->next);

	tmp_node->next = *head;

	(*head) = (*head)->next;

	tmp_node->next->next = NULL;

	tmp_node->next->prev = tmp_node;
}
