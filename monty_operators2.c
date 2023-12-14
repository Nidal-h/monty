#include "monty.h"

/**
* pop_from_stack - function that prints the top of the stack
* @head: double head pointer to the stack
* @counter: line count
*
* Return: nothing
*/
void pop_from_stack(stack_t **head, unsigned int counter)
{
	stack_t *h;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", counter);
		fclose(bus.file);
		free(bus.content);
		release_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	*head = h->next;
	free(h);
}

/**
* print_int_stack - function that prints the top of the stack
* @head: double head pointer to the stack
* @counter: line count
*
* Return: nothing
*/
void print_int_stack(stack_t **head, unsigned int counter)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", counter);
		fclose(bus.file);
		free(bus.content);
		release_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}

/**
* no_operation - function that does nothing
* @head: double head pointer to the stack
* @counter: line count
*
* Return: nothing
*/
void no_operation(stack_t **head, unsigned int counter)
{
	(void) counter;
	(void) head;
}

