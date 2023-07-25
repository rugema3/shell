#include "main.h"

/**
 * rnd_catch - changes current directory
 *
 * @cowsh: data relevant
 * Return: 1 on success
 */
int rnd_catch(data_shell *cowsh)
{
	char *tir;
	int given, fill, spoon;

	tir = cowsh->args[1];

	if (tir != NULL)
	{
		given = _strcmp("$HOME", tir);
		fill = _strcmp("~", tir);
		spoon = _strcmp("--", tir);
	}

	if (tir == NULL || !given || !fill || !spoon)
	{
		cd_to_home(cowsh);
		return (1);
	}

	if (_strcmp("-", tir) == 0)
	{
		cd_previous(cowsh);
		return (1);
	}

	if (_strcmp(".", tir) == 0 || _strcmp("..", tir) == 0)
	{
		cd_dot(cowsh);
		return (1);
	}

	cd_to(cowsh);

	return (1);
}
