#include "main.h"

/**
 * get_error - calls the error according the builtin, syntax or permission
 * @datash: data structure that contains arguments
 * @eval: error value
 * Return: error
 */
int get_error(data_shell *datash, int eval)
{
	char *error;

	switch (eval)
	{
	case -1:
		error = error_env(datash);
		break;
	case 126:
		error = error_path_126(datash);
		break;
	case 127:
		error = get_not_found_error(datash);
		break;
	case 2:
		if (_strcmp("exit", datash->args[0]) == 0)
			error = get_exit_shell_error(datash);
		else if (_strcmp("cd", datash->args[0]) == 0)
			error = get_cd_error_message(datash);
		break;
	}

	if (error)
	{
		write(STDERR_FILENO, error, _strlen(error));
		free(error);
	}

	datash->status = eval;
	return (eval);
}
