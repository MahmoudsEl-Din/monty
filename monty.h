#ifndef _MONTY_H_
#define _MONTY_H_

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/syscall.h>


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

/*main.c*/
int main(int argc, char *argv[])

/*push.c*/
void myPush(stack_t **stack, unsigned int line_number, int n);

/*pall.c*/
void myPall(stack_t **stack, unsigned int line_number);

/*pint.c*/
void myPint(stack_t **stack, unsigned int line_number);

/*pop.c*/
void myPop(stack_t **stack, unsigned int line_number);

/*swap.c*/
void mySwap(stack_t **stack, unsigned int line_number);

/*add.c*/
void myAdd(stack_t **stack, unsigned int line_number);

/*handle.c*/
int getIntFromPush(char *str, int line_number);
int findNonNumbers(char *str, int line_number);
int findNewline(char *str);

/*string.c*/
int compareStrings(char *str1, char *str2);

/*execute.c*/
void executeOpCodes(char *lines[], stack_t *stack)

#endif
