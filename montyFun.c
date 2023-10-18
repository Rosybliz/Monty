#define _GNU_SOURCE
#include "monty.h"
/**
 * readFile - reads a bytecode file and runs commands
 * @filename: pathname to file
 * @stack: pointer to the top of the stack
 */
void readFile(char *filename, stack_t **stack)
{
	char *line;
	size_t i = 0;
	int count = 1;
	instruct_func s;
	int check;
	int read;


	var_global.file = fopen(filename, "r");

	if (var_global.file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	while ((read = getline(&var_global.buffer, &i, var_global.file)) != -1)
	{
		line = parse(var_global.buffer, stack, count);
		if (line == NULL || line[0] == '#')
		{
			count++;
			continue;
		}
		s = getOpFunc(line);
		if (s == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", count, line);
			exit(EXIT_FAILURE);
		}
		s(stack, count);
		count++;
	}
	free(var_global.buffer);
	check = fclose(var_global.file);
	if (check == -1)
		exit(-1);
}

/**
 * getOpFunc -  checks opcode and returns the correct function
 * @str: the opcode
 * Return: returns a functions, or NULL on failure
 */
instruct_func getOpFunc(char *str)
{
	int i;

	instruction_t instruct[] = {
		{"push", _push},
		{"pall", _printall},
		{"pint", _printint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{"sub", _subtract},
		{"mul", _multiply},
		{"div", _divide},
		{"mod", _modulo},
		{"pchar", _printchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL},
	};

	i = 0;
	while (instruct[i].f != NULL && strcmp(instruct[i].opcode, str) != 0)
	{
		i++;
	}

	return (instruct[i].f);
}

/**
 * is_num - checks if a string is a number
 * @str: string being passed
 * Return: returns 1 if string is a number, 0 otherwise
 */
int is_num(char *str)
{
	unsigned int i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[0] == '-')
		{
			i++;
			continue;
		}
		if (!isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

/**
 * parse - parses a line for an opcode and arguments
 * @line: the line to be parsed
 * @stack: pointer to the head of the stack
 * @line_no: the current line number
 * Return: returns the opcode or null on failure
 */
char *parse(char *line, stack_t **stack, unsigned int line_no)
{
	char *opCode, *push, *arg;
	(void)stack;

	push = "push";
	opCode = strtok(line, "\n ");
	if (opCode == NULL)
		return (NULL);

	if (strcmp(opCode, push) == 0)
	{
		arg = strtok(NULL, "\n ");
		if (is_num(arg) == 1 && arg != NULL)
		{
			var_global.push_arg = atoi(arg);
		}
		else
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_no);
			exit(EXIT_FAILURE);
		}
	}
	return (opCode);
}
