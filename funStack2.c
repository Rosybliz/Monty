#include "monty.h"
/**
 * _swap - swap top of stack y second top stack
 * @stack: pointer to lists for monty stack
 * @line_no: number of line opcode occurs on
 */

void _swap(stack_t **stack, unsigned int line_no)
{
	stack_t *runner;
	int tmp;

	runner = *stack;
	if (runner == NULL || (*runner).next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_no);
		exit(EXIT_FAILURE);
	}
	tmp = (*runner).n;
	(*runner).n = runner->next->n;
	runner->next->n = tmp;
}

/**
 * _add - add top of stack y second top stack
 * @stack: pointer to lists for monty stack
 * @line_no: number of line opcode occurs on
 */

void _add(stack_t **stack, unsigned int line_no)
{
	stack_t *tmp = *stack;
	int sum = 0, i = 0;

	if (tmp == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_no);
		exit(EXIT_FAILURE);
	}

	while (tmp)
	{
		tmp = (*tmp).next;
		i++;
	}

	if (stack == NULL || (*stack)->next == NULL || i <= 1)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_no);
		exit(EXIT_FAILURE);
	}
	sum = (*stack)->next->n + (*stack)->n;
	_pop(stack, line_no);

	(*stack)->n = sum;
}

/**
 * _nop - nop top of stack y second top stack
 * @stack: pointer to lists for monty stack
 * @line_no: number of line opcode occurs on
 */

void _nop(__attribute__ ((unused))stack_t **stack,
		__attribute__ ((unused)) unsigned int line_no)
{
	;
}

/**
 * _printchar - prints the ASCII value of a number
 * @stack: pointer to the top of the stack
 * @line_no: the index of the current line
 *
 */
void _printchar(stack_t **stack, unsigned int line_no)
{
	int val;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_no);
		free(var_global.buffer);
		fclose(var_global.file);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}

	val = (*stack)->n;
	if (val > 127 || val < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_no);
		free(var_global.buffer);
		fclose(var_global.file);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}

	putchar(val);
	putchar('\n');
}

/**
 * is_alpha - checks if int is in alphabet
 * @d: int
 * Return: 1 if yes, 0 if no
 */
int is_alpha(int d)
{
	if ((d >= 97 && d <= 122) || (d >= 65 && d <= 90))
		return (1);
	else
		return (0);
}
