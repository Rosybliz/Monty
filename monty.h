#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

/*--- Struct Definitions ---*/
extern int push_arg;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO ALX  project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcoode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO ALX project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct global_variable - opcoode and its function
 * @file: the opcode
 * @push_arg: function to handle the opcode
 * @buffer: pointer to
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO ALX project
 */
typedef struct global_variable
{
	FILE *file;
	int push_arg;
	char *buffer;
} global_var;

extern global_var var_global;

void readFile(char *filename, stack_t **stack);
char *parse(char *line, stack_t **stack, unsigned int line_no);
typedef void (*instruct_func)(stack_t **stack, unsigned int line_no);
instruct_func getOpFunc(char *str);

/* Monty Functions*/
void _printall(stack_t **stack, unsigned int line_no);
void _push(stack_t **stack, unsigned int line_no);
void _printint(stack_t **stack, unsigned int line_no);
void _pop(stack_t **stack, unsigned int line_no);
void _swap(stack_t **stack, unsigned int line_no);
void _nop(stack_t **stack, unsigned int line_no);
void rotl(stack_t **stack, unsigned int line_no);
void rotr(stack_t **stack, unsigned int line_no);
void free_dlistint(stack_t *head);

/*string Functions */
void _printchar(stack_t **stack, unsigned int line_no);
void pstr(stack_t **stack, unsigned int line_no);

/*Calc Functions*/
void _subtract(stack_t **stack, unsigned int line_no);
void _add(stack_t **stack, unsigned int line_no);
void _multiply(stack_t **stack, unsigned int line_no);
void _divide(stack_t **stack, unsigned int line_no);
void _modulo(stack_t **stack, unsigned int line_no);
int is_alpha(int d);

/*Utility functions*/
void dobfree(stack_t **stack);
void dobfree2(stack_t **stack);

#endif
