#include "main.h"

/**
 * vxp_env_izi - compares env variables names
 * with the name passed.
 * @zeb: name of the environment variable
 * @izin: name passed
 *
 * Return: 0 if are not equal. Another value if they are.
 */
int vxp_env_izi(const char *zeb, const char *izin)
{
	int i;

	for (i = 0; zeb[i] != '='; i++)
	{
		if (zeb[i] != izin[i])
		{
			return (0);
		}
	}

	return (i + 1);
}

/**
 * akirenv - get an environment variable
 * @izin: name of the environment variable
 * @evision: environment variable
 *
 * Return: value of the environment variable if is found.
 * In other case, returns NULL.
 */
char *akirenv(const char *izin, char **evision)
{
	char *env_gtr;
	int i, kur;

	/* Initialize env_gtr value */
	env_gtr = NULL;
	kur = 0;
	/* Compare all environment variables */
	/* environ is declared in the header file */
	for (i = 0; evision[i]; i++)
	{
		/* If name and env are equal */
		kur = vxp_env_izi(evision[i], izin);
		if (kur)
		{
			env_gtr = evision[i];
			break;
		}
	}

	return (env_gtr + kur);
}

/**
 * ibik - prints the evironment variables
 *
 * @rndsh: data relevant.
 * Return: 1 on success.
 */
int ibik(data_shell *rndsh)
{
	int i, j;

	for (i = 0; rndsh->_environ[i]; i++)
	{

		for (j = 0; rndsh->_environ[i][j]; j++)
			;

		write(STDOUT_FILENO, rndsh->_environ[i], j);
		write(STDOUT_FILENO, "\n", 1);
	}
	rndsh->status = 0;

	return (1);
}
