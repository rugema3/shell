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
 * struct qr_var_liste - single linked list
 * @len_var: length of the variable
 * @val: value of the variable
 * @len_val: length of the value
 * @next: next node
 * Description: single linked list to store variables
 */
typedef struct qr_var_liste
{
    int len_var;
    char *val;
    int len_val;
    struct qr_var_liste *next;
} qr_var;

/**
 * struct bare_built - Builtin struct for command args.
 * @name: The name of the command builtin i.e cd, exit, env
 * @f: data type pointer function.
 */
typedef struct bare_built
{
    char *name;
    int (*f)(datacliff *rndsh);
} bare_b;

#endif /* _BIGSTRUCTURES_H_ */

