#include "monty.h"
/**
 * _push - push int to a stack
 * @stack: linked lists for monty stack
 * @line_no: number of line opcode occurs on
 */
void _push(stack_t **stack, __attribute__ ((unused))unsigned int line_no)
{
	stack_t *top;
	(void)line_no;

	top = malloc(sizeof(stack_t));
	if (top == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

        (*top).n = var_global.push_arg;
	(*top).next = *stack;
	(*top).prev = NULL;
	if (*stack != NULL)
		(*stack)->prev = top;
	*stack = top;
}

/**
 * _printall - print all function
 * @stack: pointer to linked list stack
 * @line_no: number of line opcode occurs on
 */
void _printall(stack_t **stack, __attribute__ ((unused))unsigned int line_no)
{
	stack_t *runner;

	runner = *stack;
	while (runner != NULL)
	{
		printf("%d\n",(*runner).n);
		runner = (*runner).next;
	}
}

/**
 * _printint - print int a top of stack
 * @stack: pointer to linked list stack
 * @line_no: number of line opcode occurs on
 *
 */
void _printint(stack_t **stack, unsigned int line_no)
{
	stack_t *runner;

	runner = *stack;
	if (runner == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_no);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*runner).n);
}

/**
 * _pop - remove element from  a stack or list
 *@stack: pointer to the first node
 *@line_no: integer
 *Return: void
 */
void _pop(stack_t **stack, unsigned int line_no)
{
	stack_t *nodo = *stack;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_no);
		exit(EXIT_FAILURE);
	}
	*stack = (*nodo).next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(nodo);
}

/**
 * free_dlistint - free a list
 * @head: pointer to first node
 *
 */
void free_dlistint(stack_t *head)
{
	stack_t *tmp;

	while (head != NULL)
	{
		tmp = (*head).next;
		free(head);
		head = tmp;
	}
}
