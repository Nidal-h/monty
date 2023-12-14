#include "monty.h"

/**
* process_opcode - function that executes the opcode
* @stack: head stack linked list
* @counter: line count
* @file: pointer to monty file stream
* @content: line content
*
* Return: nothing
*/
int process_opcode(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	instruction_t opst[] = {
				{"push", push_to_stack}, {"pall", print_all_stack}, {"pint", print_int_stack},
				{"pop", pop_from_stack},
				{"swap", swap_top_stack},
				{"add", stack_add},
				{"nop", no_operation},
				{"sub", stack_subtract},
				{"div", stack_divide},
				{"mul", stack_multiply},
				{"mod", stack_modulus},
				{"pchar", print_char_from_stack},
				{"pstr", print_string_stack},
				{"rotl", rotate_left_stack},
				{"rotr", rotate_right_stack},
				{"queue", enable_queue_mode},
				{"stack", print_top},
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
		release_stack(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}

