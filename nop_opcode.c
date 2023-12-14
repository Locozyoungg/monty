#include "monty.h"
/**
 * nop - Function that does nothing.
 * @stack: A double pointer to the beginning of the stack (unused).
 * @line_number: The line number of the opcode being executed (unused).
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	/* The nop opcode does nothing */
}
