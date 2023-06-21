#include <stdio.h>
#include "monty.h"
/**
 * rotr - rotates the stack to the bottom.
 * @stack: Double pointer to the head of the stack.
 * @line_number: Line number of the opcode in the file.
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *bottom, *prev;

	(void) line_number;
	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		return;
	}

	bottom = *stack;
	while (bottom->next)
	{
		bottom = bottom->next;
	}

	prev = bottom->prev;
	bottom->next = *stack;
	bottom->prev = NULL;
	prev->next = NULL;
	(*stack)->prev = bottom;
	*stack = bottom;
}
