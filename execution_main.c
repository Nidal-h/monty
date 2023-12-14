#include "monty.h"

/**
* execute - function that executes the opcode
* @stack: head stack linked list
* @counter: line count
* @file: pointer to monty file stream
* @content: line content
*
* Return: nothing
*/
int execute(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	instruction_t opst[] = {
				{"push", add_stack}, {"pall", every_stack}, {"pint", print_stack},
				{"pop", top_stack},
				{"swap", swap_stack},
				{"add", double_stack},
				{"nop", double_head_stack},
				{"sub", substrac_stack},
				{"div", divide_stack},
				{"mul", multiply_stack},
				{"mod", modulo_stack},
				{"pchar", print_char_stack},
				{"pstr", print_str_stack},
				{"rotl", rotate_stack},
				{"rotr", rotate_bottom_stack},
				{"queue", print_queue_stack},
				{"stack", head_stack},
				{NULL, NULL}
				};
	unsigned int i = 0;
	char *op;

	op = strtok(content, " \n\t");
	if (op && op[0] == '#')
		return (0);
	bus.arg = strtok(NULL, " \n\t");
	while (opst[i].opcode && op)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{	opst[i].f(stack, counter);
			return (0);
		}
		i++;
	}
	if (op && opst[i].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
		fclose(file);
		free(content);
		freeStack(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}

