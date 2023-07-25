#include "main.h"

/**
 * vxp_env_izi - compares env variables names
 * with the name passed.
 * @nenv: name of the environment variable
 * @name: name passed
 *
 * Return: 0 if are not equal. Another value if they are.
 */
int vxp_env_izi(const char *nenv, const char *name)
{
	int i;

	for (i = 0; nenv[i] != '='; i++)
	{
		if (nenv[i] != name[i])
		{
			return (0);
		}
	}

	return (i + 1);
}

/**
 * akirenv - get an environment variable
 * @name: name of the environment variable
 * @evision: environment variable
 *
 * Return: value of the environment variable if is found.
 * In other case, returns NULL.
 */
char *akirenv(const char *name, char **evision)
{
	char *ptr_env;
	int i, mov;

	/* Initialize ptr_env value */
	ptr_env = NULL;
	mov = 0;
	/* Compare all environment variables */
	/* environ is declared in the header file */
	for (i = 0; evision[i]; i++)
	{
		/* If name and env are equal */
		mov = vxp_env_izi(evision[i], name);
		if (mov)
		{
			ptr_env = evision[i];
			break;
		}
	}

	return (ptr_env + mov);
}

/**
 * ibik - prints the evironment variables
 *
 * @datash: data relevant.
 * Return: 1 on success.
 */
int ibik(data_shell *datash)
{
	int i, j;

	for (i = 0; datash->evision[i]; i++)
	{

		for (j = 0; datash->evision[i][j]; j++)
			;

		write(STDOUT_FILENO, datash->evision[i], j);
		write(STDOUT_FILENO, "\n", 1);
	}
	datash->guys = 0;

	return (1);
}
