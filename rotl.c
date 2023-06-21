#include <stdio.h>
#include "monty.h"
/**
 * rotl - rotates the stack to the top.
 * @stack: Double pointer to the head of the stack.
 * @line_number: Line number of the opcode in the file.
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *bottom;

	(void) line_number;
	if (*stack == NULL || (*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		return;
	}
	top = *stack;
	bottom = top->next;
	while (bottom->next != NULL)
	{
		bottom = bottom->next;
	}
	top->next->prev = *stack;
	*stack = top->next;
	bottom->next = top;
	top->next = NULL;
	top->prev = bottom;
}
