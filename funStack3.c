#include "monty.h"

/**
 * pstr - modify top of stack 
 * @stack: pointer to lists for monty stack
 * @line_no: number of line opcode occurs on
 */
void pstr(stack_t **stack, unsigned int line_no)
{
	stack_t *tmp = *stack;
	int c = 0;

	(void)line_no;


	while (tmp)
	{
		c = (*tmp).n;
		if (c == 0 || is_alpha(c) == 0)
			break;
		putchar(c);
		tmp = (*tmp).next;
	}
	putchar('\n');
}

/**
 * rotl - mod top of stack y second top stack
 * @stack: pointer to lists for monty stack
 * @line_no: number of line opcode occurs on
 */
void rotl(stack_t **stack, unsigned int line_no)
{
	stack_t *runner = *stack;


	int aux1 = 0;

	if (!line_no || !stack || !*stack || !(*stack)->next)
		return;

	aux1 = (*runner).n;

	while ((*runner).next)
	{
		runner = (*runner).next;
		runner->prev->n = (*runner).n;
	}

	(*runner).n = aux1;
}

/**
 * rotr - ....
 * @stack: pointer to lists for monty stack
 * @line_no: number of line opcode occurs on
 */
void rotr(stack_t **stack, unsigned int line_no)
{
	stack_t *runner = *stack;

	int aux1 = 0;

	if (!line_no || !stack || !*stack || !(*stack)->next)
		return;

	while ((*runner).next)
		runner = (*runner).next;

	aux1 = (*runner).n;

	while ((*runner).prev)
	{
		runner = (*runner).prev;
		runner->next->n = (*runner).n;
	}

	(*runner).n = aux1;
}
