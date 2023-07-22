#include "main.h"

/**
 * iher_umur - finds builtins and commands
 *
 * @rndsh: data relevant (args)
 * Return: 1 on success.
 */
int iher_umur(data_shell *rndsh)
{
	int (*ubakib)(data_shell *rndsh);

	if (rndsh->args[0] == NULL)
		return (1);

	ubakib = get_builtin(rndsh->args[0]);

	if (ubakib != NULL)
		return (ubakib(rndsh));

	return (cmd_exec(rndsh));
}
