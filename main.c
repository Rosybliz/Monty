#include "monty.h"
global_var var_global;
/**
 * main - main function for monty program
 * @ac: int num of arguments
 * @av: opcode file
 * Return: 0
 */
int main(int ac, char **av)
{
	stack_t *stack;

	stack = NULL;
	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	readFile(av[1], &stack);
	free_dlistint(stack);
	return (0);
}
