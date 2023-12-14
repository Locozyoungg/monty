#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * pop - removes the top element of the stack
 * @stack: double pointer to the head of the stack
 * @line_number: line number of the opcode
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	*stack = temp->next;

	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(temp);
}
