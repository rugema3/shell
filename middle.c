#include "main.h"
#include "bigstructures.h"

/**
 * swap_char - swaps | and & for non-printed chars
 *
 * @mettre: input string
 * @bool: type of swap
 * Return: swapped string
 */
char *swap_char(char *mettre, int bool)
{
	int i;

	if (bool == 0)
	{
		for (i = 0; mettre[i]; i++)
		{
			if (mettre[i] == '|')
			{
				if (mettre[i + 1] != '|')
					mettre[i] = 16;
				else
					i++;
			}

			if (mettre[i] == '&')
			{
				if (mettre[i + 1] != '&')
					mettre[i] = 12;
				else
					i++;
			}
		}
	}
	else
	{
		for (i = 0; mettre[i]; i++)
		{
			mettre[i] = (mettre[i] == 16 ? '|' : mettre[i]);
			mettre[i] = (mettre[i] == 12 ? '&' : mettre[i]);
		}
	}
	return (mettre);
}

/**
 * add_nodes - add separators and command lines in the lists
 *
 * @head_s: head of separator list
 * @head_l: head of command lines list
 * @mettre: input string
 * Return: no return
 */
void add_nodes(blame_lists **head_s, ligna_lista **head_l, char *mettre)
{
	int i;
	char *line;

	mettre = swap_char(mettre, 0);

	for (i = 0; mettre[i]; i++)
	{
		if (mettre[i] == ';')
			pin_stuff(head_s, mettre[i]);

		if (mettre[i] == '|' || mettre[i] == '&')
		{
			pin_stuff(head_s, mettre[i]);
			i++;
		}
	}

	line = right(mettre, ";|&");
	do {
		line = swap_char(line, 1);
		lead_stuff(head_l, line);
		line = right(NULL, ";|&");
	} while (line != NULL);

}

/**
 * go_next - go to the next command line stored
 *
 * @list_s: separator list
 * @list_l: command line list
 * @rndsh: data structure
 * Return: no return
 */
void go_next(blame_lists **list_s, ligna_lista **list_l, datacliff *rndsh)
{
	int loop_sep;
	blame_lists *ls_s;
	ligna_lista *ls_l;

	loop_sep = 1;
	ls_s = *list_s;
	ls_l = *list_l;

	while (ls_s != NULL && loop_sep)
	{

		if (rndsh->guys == 0)
		{
			if (ls_s->separator == '&' || ls_s->separator == ';')
				loop_sep = 0;
			if (ls_s->separator == '|')
				ls_l = ls_l->next, ls_s = ls_s->next;
		}
		else
		{
			if (ls_s->separator == '|' || ls_s->separator == ';')
				loop_sep = 0;
			if (ls_s->separator == '&')
				ls_l = ls_l->next, ls_s = ls_s->next;
		}
		if (ls_s != NULL && !loop_sep)
			ls_s = ls_s->next;
	}

	*list_s = ls_s;
	*list_l = ls_l;
}

/**
 * split_commands - splits command lines according to
 * the separators ;, | and &, and executes them
 *
 * @rndsh: data structure
 * @mettre: input string
 * Return: 0 to exit, 1 to continue
 */
int split_commands(datacliff *rndsh, char *mettre)
{

	blame_lists *head_s, *list_s;
	ligna_lista *head_l, *list_l;
	int loop;

	head_s = NULL;
	head_l = NULL;

	add_nodes(&head_s, &head_l, mettre);

	list_s = head_s;
	list_l = head_l;

	while (list_l != NULL)
	{
		rndsh->mettre = list_l->line;
		rndsh->kwargs = split_line(rndsh->mettre);
		loop = iher_umur(rndsh);
		free(rndsh->kwargs);


		if (loop == 0)
			break;

		go_next(&list_s, &list_l, rndsh);

		if (list_l != NULL)
			list_l = list_l->next;
	}

	jargon_stuff(&head_s);
	oblique_stuff(&head_l);

	if (loop == 0)
		return (0);
	return (1);
}

/**
 * split_line - tokenizes the input string
 *
 * @mettre: input string.
 * Return: string splitted.
 */
char **split_line(char *mettre)
{
	size_t bsize;
	size_t i;
	char **tokens;
	char *token;

	bsize = TOK_BUFSIZE;
	tokens = malloc(sizeof(char *) * (bsize));
	if (tokens == NULL)
	{
		write(STDERR_FILENO, ": allocation error\n", 18);
		exit(EXIT_FAILURE);
	}

	token = right(mettre, TOK_DELIM);
	tokens[0] = token;

	for (i = 1; token != NULL; i++)
	{
		if (i == bsize)
		{
			bsize += TOK_BUFSIZE;
			tokens = _reallocdp(tokens, i, sizeof(char *) * bsize);
			if (tokens == NULL)
			{
				write(STDERR_FILENO, ": allocation error\n", 18);
				exit(EXIT_FAILURE);
			}
		}
		token = right(NULL, TOK_DELIM);
		tokens[i] = token;
	}

	return (tokens);
}
