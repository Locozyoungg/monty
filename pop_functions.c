#include "monty.h"

/**
 * pop - remove the top element of the stack
 * @stack: pointer to the stack
 * @line_number: line number of the instruction
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	*stack = (*stack)->next;

	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(temp);
}
