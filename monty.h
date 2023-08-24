#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/uio.h>
#include <errno.h>
#include <ctype.h>
#include <string.h>
/*new header*/
#include <stdbool.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>



/* constant val*/
#define BUFFERSIZE 30

/**
 * struct stack_s - Doubly linked list representation of a stack (or queue)
 * @n: Integer
 * @prev: Points to the previous element of the stack (or queue)
 * @next: Points to the next element of the stack (or queue)
 *
 * Description: Doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;




/**
 * struct instruction_s - Opcode and its function
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
 * struct glob_glob_data - data struct for data used in multiple
 * file modules
 * @file: file name
 * @tmp: number of chars read from file data
 * @dict: data of the instruction in a dictionary
 * @buff: getline function buffer data
 * @head: pointer to linked list data
 * @line_number: file line number tracker
 * @MODE: program mode whether stack or queue
 */
typedef struct glob_glob_data
{
	FILE *file;
	char *buff;
	size_t tmp;
	instruction_t *dict;
	stack_t *head;
	unsigned int line_number;
	int MODE;
} global_glob_data_struct;

extern global_glob_data_struct glob_data;



/* new functions*/
int argnum_error(void);
void file_open_err(const char *filename);
void unknown_instruc_err(unsigned int line_number,
	char *read_opcode);
void push_error(unsigned int line_number);
void malloc_err(void);
void pint_err(unsigned int line_number);
void pop_err(unsigned int line_number);
void swap_err(unsigned int line_number);
void add_stack_err(unsigned int line_number);
void div_err(unsigned int line_number);
void sub_err(unsigned int line_number);
void div_by_zero_err(unsigned int line_number);
void multiply_err(unsigned int line_number);
void modulus_err(unsigned int line_number);
void print_char_err(unsigned int line_number);
void printch_out_of_range_err(unsigned int line_number);


int start_global_glob_data_struct(global_glob_data_struct *glob_data);
instruction_t *create_instru();
int call_funct(global_glob_data_struct *glob_data, char *read_opcode);
void free_all(void);
int _isdigit(char *string);

void pint_func(stack_t **head, unsigned int line_number);
void pop_func(stack_t **head, unsigned int line_number);
void swap_func(stack_t **head, unsigned int line_number);
void add_func(stack_t **head, unsigned int line_number);
void sub_func(stack_t **head, unsigned int line_number);
void rotl_func(stack_t **head, unsigned int line_number);
void rotr_func(stack_t **head, unsigned int line_number);
void pall_func(stack_t **head, unsigned int line_number);
void push_func(stack_t **head, unsigned int line_number);
void div_func(stack_t **head, unsigned int line_number);
void mul_func(stack_t **head, unsigned int line_number);
void mod_func(stack_t **head, unsigned int line_number);
void pchar_func(stack_t **head, unsigned int line_number);
void pstr_func(stack_t **head, unsigned int line_number);
void stack_func(stack_t **head, unsigned int line_number);
void queue_func(stack_t **head, unsigned int line_number);

#endif /* MONTY_H */
