#include <stdlib.h>
#include "lists.h"

/**
 * free_listint2 - frees listint_t list and sets head to NULL.
 * @head: pointer to the head of the list.
 */
void free_listint2(listint_t **head)
{
	listint_t *current, *temp;

	if (head == NULL)
		return; /* Nothing to free, head is already NULL */

	current = *head;

	while (current != NULL)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
	*head = NULL; /* Set the head to NULL to indicate empty list */
}
