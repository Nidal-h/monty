#include "monty.h"

/**
* freeStack - function that frees a doubly linked list
* @head: head pointer to the stack
*
* Return: nothing
*/
void freeStack(stack_t *head)
{
	stack_t *temp;

	temp = head;
	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}

/**
* head_stack - function that prints the top
* @head: head of stack
* @counter: line count
*
* Return: nothing
*/
void head_stack(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;
	bus.lifi = 0;
}
