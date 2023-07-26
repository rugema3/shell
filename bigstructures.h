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
 * @separateur: ; | &
 * @suivant: next node
 * Description: single linked list to store separators
 */
typedef struct blame_lists_q
{
    char separateur;
    struct blame_lists_q *suivant;
} blame_lists;

/**
 * struct ligna_lista_s - single linked list
 * @ligna: command line
 * @suivant: next node
 * Description: single linked list to store command lines
 */
typedef struct ligna_lista_s
{
    char *ligna;
    struct ligna_lista_s *suivant;
} ligna_lista;

/**
 * struct qr_var_liste - single linked list
 * @blop_var: length of the variable
 * @blopval: value of the variable
 * @blop_val: length of the value
 * @suivant: next node
 * Description: single linked list to store variables
 */
typedef struct qr_var_liste
{
    int blop_var;
    char *blopval;
    int blop_val;
    struct qr_var_liste *suivant;
} qr_var;

/**
 * struct bare_built - Builtin struct for command args.
 * @nom: The name of the command builtin i.e cd, exit, env
 * @f: data type pointer function.
 */
typedef struct bare_built
{
    char *nom;
    int (*f)(datacliff *rndsh);
} bare_b;

#endif /* _BIGSTRUCTURES_H_ */

