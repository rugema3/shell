#include "main.h"

/**
 * sleeve_chr - counts the repetitions of a char
 *
 * @injiza: input string
 * @verb: index
 * Return: repetitions
 */
int sleeve_chr(char *injiza, int verb)
{
	if (*(injiza - 1) == *injiza)
		return (sleeve_chr(injiza - 1, verb + 1));

	return (verb);
}

/**
 * snoop_error_og - finds syntax errors
 *
 * @injiza: input string
 * @verb: index
 * @snoop: last char read
 * Return: index of error. 0 when there are no
 * errors
 */
int snoop_error_og(char *injiza, int verb, char snoop)
{
	int ball;

	ball = 0;
	if (*injiza == '\0')
		return (0);

	if (*injiza == ' ' || *injiza == '\t')
		return (snoop_error_og(injiza + 1, verb + 1, snoop));

	if (*injiza == ';')
		if (snoop == '|' || snoop == '&' || snoop == ';')
			return (verb);

	if (*injiza == '|')
	{
		if (snoop == ';' || snoop == '&')
			return (verb);

		if (snoop == '|')
		{
			ball = sleeve_chr(injiza, 0);
			if (ball == 0 || ball > 1)
				return (verb);
		}
	}

	if (*injiza == '&')
	{
		if (snoop == ';' || snoop == '|')
			return (verb);

		if (snoop == '&')
		{
			ball = sleeve_chr(injiza, 0);
			if (ball == 0 || ball > 1)
				return (verb);
		}
	}

	return (snoop_error_og(injiza + 1, verb + 1, *injiza));
}

/**
 * econ_char - finds index of the first char
 *
 * @injiza: input string
 * @verb: index
 * Return: 1 if there is an error. 0 in other case.
 */
int econ_char(char *injiza, int *verb)
{

	for (*verb = 0; injiza[*verb]; *verb += 1)
	{
		if (injiza[*verb] == ' ' || injiza[*verb] == '\t')
			continue;

		if (injiza[*verb] == ';' || injiza[*verb] == '|' || injiza[*verb] == '&')
			return (-1);

		break;
	}

	return (0);
}

/**
 * erakan_syntax_ikos - prints when a syntax error is found
 *
 * @rndsh: data structure
 * @injiza: input string
 * @verb: index of the error
 * @cool: to control msg error
 * Return: no return
 */
void erakan_syntax_ikos(data_shell *rndsh, char *injiza, int verb, int cool)
{
	char *hp, *hp2, *hp3, *ikos, *counter;
	int ubul;

	if (injiza[verb] == ';')
	{
		if (cool == 0)
			hp = (injiza[verb + 1] == ';' ? ";;" : ";");
		else
			hp = (injiza[verb - 1] == ';' ? ";;" : ";");
	}

	if (injiza[verb] == '|')
		hp = (injiza[verb + 1] == '|' ? "||" : "|");

	if (injiza[verb] == '&')
		hp = (injiza[verb + 1] == '&' ? "&&" : "&");

	hp2 = ": Syntax error: \"";
	hp3 = "\" unexpected\n";
	counter = conv_num(rndsh->counter);
	ubul = guru(rndsh->av[0]) + guru(counter);
	ubul += guru(hp) + guru(hp2) + guru(hp3) + 2;

	ikos = malloc(sizeof(char) * (ubul + 1));
	if (ikos == 0)
	{
		free(counter);
		return;
	}
	_strap_y(ikos, rndsh->av[0]);
	_strap_y(ikos, ": ");
	_strap_y(ikos, counter);
	_strap_y(ikos, hp2);
	_strap_y(ikos, hp);
	_strap_y(ikos, hp3);
	_strap_y(ikos, "\0");

	write(STDERR_FILENO, ikos, ubul);
	free(ikos);
	free(counter);
}

/**
 * syntax_error_check - intermediate function to
 * find and print a syntax error
 *
 * @rndsh: data structure
 * @injiza: input string
 * Return: 1 if there is an error. 0 in other case
 */
int syntax_error_check(data_shell *rndsh, char *injiza)
{
	int tagil = 0;
	int gy_char = 0;
	int verb = 0;

	gy_char = econ_char(injiza, &tagil);
	if (gy_char == -1)
	{
		erakan_syntax_ikos(rndsh, injiza, tagil, 0);
		return (1);
	}

	verb = snoop_error_og(injiza + tagil, 0, *(injiza + tagil));
	if (verb != 0)
	{
		erakan_syntax_ikos(rndsh, injiza, tagil + verb, 1);
		return (1);
	}

	return (0);
}
