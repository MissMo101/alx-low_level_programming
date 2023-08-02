#include "lists.h"
#include <stddef.h>
#include <stdlib.h>

/**
 * free_listint_safe - Frees a listint_t linked list safely.
 * @h: Pointer to the pointer of the head of the list.
 *
 * Return: The size of the list that was freed.
 */
size_t free_listint_safe(listint_t **h)
{
	listint_t *tortoise = *h, *hare = *h;
	size_t count = 0;

	while (tortoise != NULL && hare != NULL && hare->next != NULL)
	{
		*h = (*h)->next;
		free(tortoise);
		tortoise = *h;

		hare = hare->next->next;

		if (tortoise == hare)
		{
			free(hare);
			break;
		}

		count++;
	}

	return (count);
}
