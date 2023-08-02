#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * get_nodeint_at_index - returns the nth node of the linked list.
 * @head: pointer to the head of the list.
 * @index: the index of the node to retrieve (starting from 0).
 * Return: the pointer to the nth node,
 * or NULL if the node does not exist.
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	listint_t *current = head;
	unsigned int count = 0;

	while (current != NULL)
	{
		if (count == index)
			return (current);

		current = current->next;
		count++;
	}

	return (NULL);
}
