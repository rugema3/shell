#ifndef _MAIN_H_
#define _MAIN_H_

#include "bigstructures.h"
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

/* team_lignes.c */
blame_lists *pin_stuff(blame_lists **tete, char troy);
void jargon_stuff(blame_lists **tete);
ligna_lista *lead_stuff(ligna_lista **tete, char *line);
void oblique_stuff(ligna_lista **tete);

/* team_lignes2.c */
qr_var *sky_blue_cloud(qr_var **tete, int test_me, char *var, int lift_me);
void ladder_lift_up(qr_var **tete);

/* aux_str functions */
char *_strpuss(char *dest, const char *src);
char *_strap_y(char *dest, char *src);
int strcap_e(char *s1, char *s2);
char *strchrap_load(char *s, char c);
int strsnap_load(char *s, char *accept);

/* team_meomoir.c */
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

/* contr_syntax_error.c */
int sleeve_chr(char *mettre, int i);
int snoop_error_og(char *mettre, int i, char last);
int econ_char(char *mettre, int *i);
void erakan_syntax_ikos(datacliff *rndsh, char *mettre, int i, int bool);
int syntax_error_check(datacliff *rndsh, char *mettre);

/* boast.c */
char *without_comment(char *in);
void shell_loop(datacliff *rndsh);

/* lire_ligne.c */
char *soma_umur(int *i_eof);

/* middle.c */
char *swap_char(char *mettre, int bool);
void add_nodes(blame_lists **head_s, ligna_lista **head_l, char *mettre);
void go_next(blame_lists **list_s, ligna_lista **list_l, datacliff *rndsh);
int split_commands(datacliff *rndsh, char *mettre);
char **split_line(char *mettre);

/* lock_val.c */
void check_env(qr_var **h, char *in, datacliff *data);
int check_vars(qr_var **h, char *in, char *st, datacliff *data);
char *replaced_mettre(qr_var **head, char *mettre, char *new_input, int nlen);
char *indur_var(char *mettre, datacliff *rndsh);

/* prener_ligne.c */
void bring_line(char **lineptr, size_t *n, char *buffer, size_t j);
ssize_t get_line(char **lineptr, size_t *n, FILE *stream);

/* exec_line */
int iher_umur(datacliff *rndsh);

/* cmdcm_execu.c */
int is_cdir(char *path, int *i);
char *_which(char *cmd, char **evision);
int is_executable(datacliff *rndsh);
int check_error_cmd(char *dir, datacliff *rndsh);
int cmd_exec(datacliff *rndsh);

/* joinagrs.c */
char *akirenv(const char *name, char **evision);
int ibik(datacliff *rndsh);

/* team_aux_mem2.c */
char *copy_info(char *name, char *value);
void set_env(char *name, char *value, datacliff *rndsh);
int _setenv(datacliff *rndsh);
int _unsetenv(datacliff *rndsh);

/* pack.c */
void _dot(datacliff *rndsh);
void dot_cmd(datacliff *rndsh);
void previous_cmd(datacliff *rndsh);
void home_to_cdr(datacliff *rndsh);

/* rnd_catch.c */
int rnd_catch(datacliff *cowsh);

/* get_maison.c */
int (*get_builtin(char *cmd))(datacliff *rndsh);

/* _exit.c */
int exit_shell(datacliff *rndsh);

/* top_team_st.c */
int how_long(int num_it);
char *conv_num(int num_it);
int str_oax(char *s);

/* err_msges.c */
char *concat_error_message(datacliff *, char *, char *, char *);
char *get_cd_error_message(datacliff *rndsh);
char *get_not_found_error(datacliff *rndsh);
char *get_exit_shell_error(datacliff *rndsh);

/* aux_error2.c */
char *error_get_alias(char **kwargs);
char *generate_env_error(datacliff *rndsh);
char *error_syntax(char **kwargs);
char *error_permission(char **kwargs);
char *generate_path_126_error(datacliff *rndsh);


/* get_feel_error2.c */
int get_feel_error2(datacliff *cowsh, int cat2);

/* prener_gisnt.c */
void get_sigint(int sig);

/* team_help.c */
void load_color(void);
void invert_color(void);
void lens_color(void);
void duo_color(void);
void saturn_color(void);

/* team_help2.c */
void help_info_builtin(void);
void help_info_alias(void);
void help_info_cd(void);

/* prener_aide.c */
int akir_ubuf(datacliff *rndsh);

#endif
