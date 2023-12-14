#include "monty.h"

/**
* top_stack - function that prints the top of the stack
* @head: double head pointer to the stack
* @counter: line count
*
* Return: nothing
*/
void top_stack(stack_t **head, unsigned int counter)
{
	stack_t *h;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", counter);
		fclose(bus.file);
		free(bus.content);
		freeStack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	*head = h->next;
	free(h);
}

/**
* print_stack - function that prints the top of the stack
* @head: double head pointer to the stack
* @counter: line count
*
* Return: nothing
*/
void print_stack(stack_t **head, unsigned int counter)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", counter);
		fclose(bus.file);
		free(bus.content);
		freeStack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}

/**
* double_head_stack - function that does nothing
* @head: double head pointer to the stack
* @counter: line count
*
* Return: nothing
*/
void double_head_stack(stack_t **head, unsigned int counter)
{
	(void) counter;
	(void) head;
}

