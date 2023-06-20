#include "monty.h"
/**
 * pall - prints the values on stack
 * @stack: Double pointer to head of the stack
 * @line_number: Current line number in the Monty file
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	(void)line_number;

	while (current != NULL)
	{
		printf("%d ", current->n);
		current = current->next;
	}
}
