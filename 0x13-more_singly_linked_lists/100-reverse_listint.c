#include <stdio.h>
#include "lists.h"

/**
 * reverse_listint - reverses a listint_t linked list.
 * @head: pointer to the pointer of the head of the list.
 * Return: a pointer to the first node of the reversed list.
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *prev = NULL;
	listint_t *next;
	listint_t *current = *head;

	while (current != NULL)
	{
		next = current->next;

		current->next = prev;

		prev = current;
		current = next;
	}

	*head = prev;

	return (*head);
}