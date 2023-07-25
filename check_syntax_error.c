#include "main.h"

/**
 * sleeve_chr - counts the repetitions of a char
 *
 * @injiza: input string
 * @j: index
 * Return: repetitions
 */
int sleeve_chr(char *injiza, int j)
{
	if (*(injiza - 1) == *injiza)
		return (sleeve_chr(injiza - 1, j + 1));

	return (j);
}

/**
 * snoop_error_og - finds syntax errors
 *
 * @injiza: input string
 * @j: index
 * @snoop: last char read
 * Return: index of error. 0 when there are no
 * errors
 */
int snoop_error_og(char *injiza, int j, char snoop)
{
	int ball;

	ball = 0;
	if (*injiza == '\0')
		return (0);

	if (*injiza == ' ' || *injiza == '\t')
		return (snoop_error_og(injiza + 1, j + 1, snoop));

	if (*injiza == ';')
		if (snoop == '|' || snoop == '&' || snoop == ';')
			return (j);

	if (*injiza == '|')
	{
		if (snoop == ';' || snoop == '&')
			return (j);

		if (snoop == '|')
		{
			ball = sleeve_chr(injiza, 0);
			if (ball == 0 || ball > 1)
				return (j);
		}
	}

	if (*injiza == '&')
	{
		if (snoop == ';' || snoop == '|')
			return (j);

		if (snoop == '&')
		{
			ball = sleeve_chr(injiza, 0);
			if (ball == 0 || ball > 1)
				return (j);
		}
	}

	return (snoop_error_og(injiza + 1, j + 1, *injiza));
}

/**
 * econ_char - finds index of the first char
 *
 * @injiza: input string
 * @j: index
 * Return: 1 if there is an error. 0 in other case.
 */
int econ_char(char *injiza, int *j)
{

	for (*j = 0; injiza[*j]; *j += 1)
	{
		if (injiza[*j] == ' ' || injiza[*j] == '\t')
			continue;

		if (injiza[*j] == ';' || injiza[*j] == '|' || injiza[*j] == '&')
			return (-1);

		break;
	}

	return (0);
}


/**
 * erakan_syntax_ikos - prints when a syntax error is found
 * conv_num - function that takes an integer argument and returns a char
 * @rndsh: data structure
 * @injiza: input string
 * @j: index of the error
 * @cool: to control msg error
 * Return: no return
 */
void erakan_syntax_ikos(data_shell *rndsh, char *injiza, int j, int cool)
{
	char *hp, *hp2, *hp3, *ikos, *counter;
	int ubul;

	if (injiza[j] == ';')
	{
		if (cool == 0)
			hp = (injiza[j + 1] == ';' ? ";;" : ";");
		else
			hp = (injiza[j - 1] == ';' ? ";;" : ";");
	}

	if (injiza[j] == '|')
		hp = (injiza[j + 1] == '|' ? "||" : "|");

	if (injiza[j] == '&')
		hp = (injiza[j + 1] == '&' ? "&&" : "&");

	hp2 = ": Syntax error: \"";
	hp3 = "\" unexpected\n";
	counter = conv_num(rndsh->counter);
	ubul = _strlen(rndsh->av[0]) + _strlen(counter);
	ubul += _strlen(hp) + _strlen(hp2) + _strlen(hp3) + 2;

	ikos = malloc(sizeof(char) * (ubul + 1));
	if (ikos == 0)
	{
		free(counter);
		return;
	}
	_strcp_y(ikos, rndsh->av[0]);
	_strxat(ikos, ": ");
	_strxat(ikos, counter);
	_strxat(ikos, hp2);
	_strxat(ikos, hp);
	_strxat(ikos, hp3);
	_strxat(ikos, "\0");

	write(STDERR_FILENO, ikos, ubul);
	free(ikos);
	free(counter);
}

/**
 * check_syntax_error - intermediate function to
 * find and print a syntax error
 *
 * @rndsh: data structure
 * @input: input string
 * Return: 1 if there is an error. 0 in other case
 */
int check_syntax_error(data_shell *rndsh, char *input)
{
	int tagil = 0;
	int gy_char = 0;
	int j = 0;

	gy_char = econ_char(input, &tagil);
	if (gy_char == -1)
	{
		erakan_syntax_ikos(rndsh, input, tagil, 0);
		return (1);
	}

	j = snoop_error_og(input + tagil, 0, *(input + tagil));
	if (j != 0)
	{
		erakan_syntax_ikos(rndsh, input, tagil + j, 1);
		return (1);
	}

	return (0);
}
