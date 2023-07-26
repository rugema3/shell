#include "main.h"

/**
 * iher_umur - finds builtins and commands
 *
 * @rndsh: data relevant (args)
 * Return: 1 on success.
 */
int iher_umur(datacliff *rndsh)
{
	int (*ubakib)(datacliff *rndsh);

	if (rndsh->kwargs[0] == NULL)
		return (1);

	ubakib = get_builtin(rndsh->kwargs[0]);

	if (ubakib != NULL)
		return (ubakib(rndsh));

	return (cmd_exec(rndsh));
}
