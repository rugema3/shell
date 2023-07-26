#ifndef _BIGSTRUCTURES_H_
#define _BIGSTRUCTURES_H_

/**
 * struct data_cliff - struct that contains all relevant data on runtime
 * @evr: argument vector
 * @mettre: command line written by the user
 * @kwargs: tokens of the command line
 * @guys: last status of the shell
 * @compteur: lines counter
 * @evision: environment variable
 * @id_pid: process ID of the shell
 */
typedef struct data_cliff
{
    char **evr;
    char *mettre;
    char **kwargs;
    int guys;
    int compteur;
    char **evision;
    char *id_pid;
} datacliff;

/**
 * struct blame_lists_q - single linked list
 * @separator: ; | &
 * @next: next node
 * Description: single linked list to store separators
 */
typedef struct blame_lists_q
{
    char separator;
    struct blame_lists_q *next;
} blame_lists;

/**
 * struct ligna_lista_s - single linked list
 * @line: command line
 * @next: next node
 * Description: single linked list to store command lines
 */
typedef struct ligna_lista_s
{
    char *line;
    struct ligna_lista_s *next;
} ligna_lista;

/**
 * struct r_var_list - single linked list
 * @len_var: length of the variable
 * @val: value of the variable
 * @len_val: length of the value
 * @next: next node
 * Description: single linked list to store variables
 */
typedef struct r_var_list
{
    int len_var;
    char *val;
    int len_val;
    struct r_var_list *next;
} r_var;

/**
 * struct builtin_s - Builtin struct for command args.
 * @name: The name of the command builtin i.e cd, exit, env
 * @f: data type pointer function.
 */
typedef struct builtin_s
{
    char *name;
    int (*f)(datacliff *rndsh);
} builtin_t;

#endif /* _BIGSTRUCTURES_H_ */

