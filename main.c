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

	for (i = 0; rndsh->evision[i]; i++)
	{
		free(rndsh->evision[i]);
	}

	free(rndsh->evision);
	free(rndsh->pid);
}

/**
 * ubaka_data - Initialize data structure
 *
 * @rndsh: data structure
 * @evr: argument vector
 * Return: no return
 */
void ubaka_data(data_shell *rndsh, char **evr)
{
	unsigned int i;

	rndsh->evr = evr;
	rndsh->input = NULL;
	rndsh->args = NULL;
	rndsh->guys = 0;
	rndsh->counter = 1;

	for (i = 0; environ[i]; i++)
		;

	rndsh->evision = malloc(sizeof(char *) * (i + 1));

	for (i = 0; environ[i]; i++)
	{
		rndsh->evision[i] = haut(environ[i]);
	}

	rndsh->evision[i] = NULL;
	rndsh->pid = conv_num(getpid());
}

/**
 * maix - Entry point
 *
 * @ax: argument count
 * @evr: argument vector
 *
 * Return: 0 on success.
 */
int main(int ax, char **evr)
{
	data_shell rndsh;
	(void) ax;

	signal(SIGINT, get_sigint);
	ubaka_data(&rndsh, evr);
	shell_loop(&rndsh);
	got_data(&rndsh);
	if (rndsh.guys < 0)
		return (255);
	return (rndsh.guys);
}
