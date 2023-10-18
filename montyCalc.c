#include "monty.h"

/**
 * _subtract - sub top of stack by second top stack
 * @stack: pointer to lists for monty stack
 * @line_no: number of line opcode occurs on
 */
void _subtract(stack_t **stack, unsigned int line_no)
{
	stack_t *tmp = *stack;
	int sub = 0, i = 0;

	if (tmp == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_no);
		exit(EXIT_FAILURE);
	}

	while (tmp)
	{
		tmp = (*tmp).next;
		i++;
	}

	if (stack == NULL || (*stack)->next == NULL || i <= 1)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_no);
		exit(EXIT_FAILURE);
	}
	sub = (*stack)->next->n - (*stack)->n;
	_pop(stack, line_no);

	(*stack)->n = sub;
}

/**
 * _multipy - multiply top of stack by second top stack
 * @stack: pointer to lists for monty stack
 * @line_no: number of line opcode occurs on
 */
void _multiply(stack_t **stack, unsigned int line_no)
{
	int ax;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_no);
		free(var_global.buffer);
		fclose(var_global.file);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		ax = (*stack)->n;
		_pop(stack, line_no);
		(*stack)->n *= ax;
	}
}

/**
 * _divide - divide top of stack by second top stack
 * @stack: pointer to lists for monty stack
 * @line_no: number of line opcode occurs on
 */
void _divide(stack_t **stack, unsigned int line_no)
{
	int div = 0;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_no);
		free(var_global.buffer);
		fclose(var_global.file);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}
	else if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_no);
		free(var_global.buffer);
		fclose(var_global.file);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		div = (*stack)->n;
		_pop(stack, line_no);
		(*stack)->n /= div;
	}
}

/**
 * _modify - modify top of stack y second top stack
 * @stack: pointer to lists for monty stack
 * @line_no: number of line opcode occurs on
 */
void _modulo(stack_t **stack, unsigned int line_no)
{
	int md = 0;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_no);
		free(var_global.buffer);
		fclose(var_global.file);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}
	else if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_no);
		free(var_global.buffer);
		fclose(var_global.file);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		md = (*stack)->n;
		_pop(stack, line_no);
		(*stack)->n %= md;
	}
}
