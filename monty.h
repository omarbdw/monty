#ifndef __MONTY_H__
#define __MONTY_H__

#define _GNU_SOURCE

/*Includes*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>


/* Structs */
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
int n;
struct stack_s *prev;
struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
char *opcode;
void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


/**
 * struct global_s - Global structure for Monty interpreter
 * @file: file pointer to the script file
 * @lineContent: pointer to the current line content being processed
 * @valueArg: pointer to the argument value of the current line being processed
 */
typedef struct global_s
{
FILE *file;
char *lineContent;
char *valueArg;
} global_t;

extern global_t global;


#define SUCCESS 0
#define FAILURE 1
#define UNUSED_PARAMETER __attribute__((unused))



/**Functions*/
void pallFunc(stack_t **stackHead, __attribute__((unused))\
unsigned int counter);
int execute(char *lineContent, stack_t **stack, int counter, FILE *file);
void pushFunc(stack_t **head, unsigned int counter);
void pintFunc(stack_t **stackHead, unsigned int counter);
void popFunc(stack_t **stackHead, unsigned int counter);
void swapFunc(stack_t **stackHead, unsigned int counter);
void addFunc(stack_t **stackHead, unsigned int counter);
void nopFunc(stack_t **stackHead, unsigned int counter);
void subFunc(stack_t **stackHead, unsigned int counter);
void addNode(stack_t **head, int value);
void divFunc(stack_t **stackHead, unsigned int counter);
void mulFunc(stack_t **stackHead, unsigned int counter);
void freeStack(stack_t **head);







#endif /* __MONTY_H__ */
