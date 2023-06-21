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
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
		return;

	bottom = *stack;
	while (bottom->next)
		bottom = bottom->next;

	prev = bottom->prev;
	prev->next = NULL;
	bottom->prev = NULL;
	bottom->next = *stack;
	(*stack)->prev = bottom;
	*stack = bottom;
}
