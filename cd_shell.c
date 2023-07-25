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
		given = strcap_e("$HOME", tir);
		fill = strcap_e("~", tir);
		spoon = strcap_e("--", tir);
	}

	if (tir == NULL || !given || !fill || !spoon)
	{
		home_to_cdr(cowsh);
		return (1);
	}

	if (strcap_e("-", tir) == 0)
	{
		previous_cmd(cowsh);
		return (1);
	}

	if (strcap_e(".", tir) == 0 || strcap_e("..", tir) == 0)
	{
		_dot(cowsh);
		return (1);
	}

	dot_cmd(cowsh);

	return (1);
}
