#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"
/**
 * opcode - function for running builtins
 * @stack: stack given by main
 * @str: string to compare
 * @line_number: Line number of the opcode in the file
 * Return: nothing
 */
void opcode(stack_t **stack, char *str, unsigned int line_number)
{
	int i = 0;

	instruction_t op[] = INSTRUCTIONS;

	if (!strcmp(str, "stack"))
	{
		global.data_struct = 1;
		return;
	}
	if (!strcmp(str, "queue"))
	{
		global.data_struct = 0;
		return;
	}

	while (op[i].opcode)
	{
		if (strcmp(op[i].opcode, str) == 0)
		{
			op[i].f(stack, line_number);
			return;
		}
		i++;
	}

	if (strcmp(str, "nop") == 0)
	{
		return;
	}

	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, str);
	exit( EXIT_FAILURE);
}
