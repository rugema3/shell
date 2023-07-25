#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <limits.h>

#define BUFSIZE 1024
#define TOK_BUFSIZE 128
#define TOK_DELIM " \t\r\n\a"

/* Points to an array of pointers to strings called the "environment" */
extern char **environ;


/**
 * struct data - struct that contains all relevant data on runtime
 * @evr: argument vector
 * @input: command line written by the user
 * @args: tokens of the command line
 * @guys: last status of the shell
 * @counter: lines counter
 * @evision: environment variable
 * @pid: process ID of the shell
 */
typedef struct data
{
	char **evr;
	char *input;
	char **args;
	int guys;
	int counter;
	char **evision;
	char *pid;
} data_shell;

/**
 * struct sep_list_s - single linked list
 * @separator: ; | &
 * @next: next node
 * Description: single linked list to store separators
 */
typedef struct sep_list_s
{
	char separator;
	struct sep_list_s *next;
} sep_list;

/**
 * struct line_list_s - single linked list
 * @line: command line
 * @next: next node
 * Description: single linked list to store command lines
 */
typedef struct line_list_s
{
	char *line;
	struct line_list_s *next;
} line_list;

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
	int (*f)(data_shell *rndsh);
} builtin_t;


/* aux_lists.c */
sep_list *pin_stuff(sep_list **tete, char troy);
void jargon_stuff(sep_list **tete);
line_list *lead_stuff(line_list **tete, char *line);
void oblique_stuff(line_list **tete);

/* aux_lists2.c */
r_var *sky_blue_cloud(r_var **tete, int test_me, char *var, int lift_me);
void ladder_lift_up(r_var **tete);

/* aux_str functions */
char *_strpuss(char *dest, const char *src);
char *_strap_y(char *dest, char *src);
int strcap_e(char *s1, char *s2);
char *strchrap_load(char *s, char c);
int strsnap_load(char *s, char *accept);

/* aux_mem.c */
void _memcpy(void *newptr, const void *ptr, unsigned int size);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char **_reallocdp(char **ptr, unsigned int old_size, unsigned int new_size);

/* aux_str2.c */
char *haut(const char *s);
int guru(const char *s);
int cetera(char str[], const char *delim);
char *right(char str[], const char *delim);
int cnombre(const char *s);

/* aux_str3.c */
void rem_string(char *s);

/* check_syntax_error.c */
int sleeve_chr(char *input, int i);
int snoop_error_og(char *input, int i, char last);
int econ_char(char *input, int *i);
void erakan_syntax_ikos(data_shell *rndsh, char *input, int i, int bool);
int syntax_error_check(data_shell *rndsh, char *input);

/* shell_loop.c */
char *without_comment(char *in);
void shell_loop(data_shell *rndsh);

/* read_line.c */
char *soma_umur(int *i_eof);

/* split.c */
char *swap_char(char *input, int bool);
void add_nodes(sep_list **head_s, line_list **head_l, char *input);
void go_next(sep_list **list_s, line_list **list_l, data_shell *rndsh);
int split_commands(data_shell *rndsh, char *input);
char **split_line(char *input);

/* rep_var.c */
void check_env(r_var **h, char *in, data_shell *data);
int check_vars(r_var **h, char *in, char *st, data_shell *data);
char *replaced_input(r_var **head, char *input, char *new_input, int nlen);
char *indur_var(char *input, data_shell *rndsh);

/* get_line.c */
void bring_line(char **lineptr, size_t *n, char *buffer, size_t j);
ssize_t get_line(char **lineptr, size_t *n, FILE *stream);

/* exec_line */
int iher_umur(data_shell *rndsh);

/* cmd_exec.c */
int is_cdir(char *path, int *i);
char *_which(char *cmd, char **evision);
int is_executable(data_shell *rndsh);
int check_error_cmd(char *dir, data_shell *rndsh);
int cmd_exec(data_shell *rndsh);

/* env1.c */
char *akirenv(const char *name, char **evision);
int ibik(data_shell *rndsh);

/* env2.c */
char *copy_info(char *name, char *value);
void set_env(char *name, char *value, data_shell *rndsh);
int _setenv(data_shell *rndsh);
int _unsetenv(data_shell *rndsh);

/* cd.c */
void _dot(data_shell *rndsh);
void dot_cmd(data_shell *rndsh);
void previous_cmd(data_shell *rndsh);
void home_to_cdr(data_shell *rndsh);

/* rnd_catch.c */
int rnd_catch(data_shell *cowsh);

/* get_builtin */
int (*get_builtin(char *cmd))(data_shell *rndsh);

/* _exit.c */
int exit_shell(data_shell *rndsh);

/* aux_stdlib.c */
int how_long(int num_it);
char *conv_num(int num_it);
int str_oax(char *s);

/* aux_error1.c */
char *concat_error_message(data_shell *, char *, char *, char *);
char *get_cd_error_message(data_shell *rndsh);
char *get_not_found_error(data_shell *rndsh);
char *get_exit_shell_error(data_shell *rndsh);

/* aux_error2.c */
char *error_get_alias(char **args);
char *generate_env_error(data_shell *rndsh);
char *error_syntax(char **args);
char *error_permission(char **args);
char *generate_path_126_error(data_shell *rndsh);


/* get_feel_error2.c */
int get_feel_error2(data_shell *cowsh, int cat2);

/* get_sigint.c */
void get_sigint(int sig);

/* aux_help.c */
void load_color(void);
void invert_color(void);
void lens_color(void);
void duo_color(void);
void saturn_color(void);

/* aux_help2.c */
void help_info_builtin(void);
void help_info_alias(void);
void help_info_cd(void);

/* get_help.c */
int akir_ubuf(data_shell *rndsh);

#endif
