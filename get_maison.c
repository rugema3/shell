#include "main.h"

/**
 * get_builtin - builtin that pais the command in the arg
 * @cmd: command
 * Return: function pointer of the builtin command
 */
int (*get_builtin(char *cmd))(datacliff *)
{
	bare_b builtin[] = {
		{ "env", ibik },
		{ "exit", exit_shell },
		{ "setenv", _setenv },
		{ "unsetenv", _unsetenv },
		{ "cd", rnd_catch },
		{ "help", akir_ubuf },
		{ NULL, NULL }
	};
	int i;

	for (i = 0; builtin[i].nom; i++)
	{
		if (strcap_e(builtin[i].nom, cmd) == 0)
			break;
	}

	return (builtin[i].f);
}
