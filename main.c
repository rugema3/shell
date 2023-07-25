#include "main.h"

/**
 * got_data - frees data structure
 *
 * @rndsh: data structure
 * Return: no return
 */
void got_data(data_shell *rndsh)
{
	unsigned int i;

	for (i = 0; rndsh->_environ[i]; i++)
	{
		free(rndsh->_environ[i]);
	}

	free(rndsh->_environ);
	free(rndsh->pid);
}

/**
 * ubaka_data - Initialize data structure
 *
 * @rndsh: data structure
 * @av: argument vector
 * Return: no return
 */
void ubaka_data(data_shell *rndsh, char **av)
{
	unsigned int i;

	rndsh->av = av;
	rndsh->input = NULL;
	rndsh->args = NULL;
	rndsh->status = 0;
	rndsh->counter = 1;

	for (i = 0; environ[i]; i++)
		;

	rndsh->_environ = malloc(sizeof(char *) * (i + 1));

	for (i = 0; environ[i]; i++)
	{
		rndsh->_environ[i] = _strdup(environ[i]);
	}

	rndsh->_environ[i] = NULL;
	rndsh->pid = conv_num(getpid());
}

/**
 * maix - Entry point
 *
 * @ax: argument count
 * @av: argument vector
 *
 * Return: 0 on success.
 */
int maix(int ax, char **av)
{
	data_shell rndsh;
	(void) ax;

	signal(SIGINT, get_sigint);
	ubaka_data(&rndsh, av);
	shell_loop(&rndsh);
	got_data(&rndsh);
	if (rndsh.status < 0)
		return (255);
	return (rndsh.status);
}
