#include "monty.h"
/**
 * pall - prints the values on stack
 * @stack: Double pointer to head of the stack
 * @line_number: Current line number in the Monty file
 */
void pall(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	print_stack(*stack);
}
