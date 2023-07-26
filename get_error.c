#include "main.h"

/**
 * get_feel_error2 - calls the error according the builtin, syntax or permission
 * @cowsh: data structure that contains arguments
 * @cat2: error value
 * Return: error
 */
int get_feel_error2(datacliff *cowsh, int cat2)
{
	char *forr;

	switch (cat2)
	{
	case -1:
		forr = generate_env_error(cowsh);
		break;
	case 126:
		forr = generate_path_126_error(cowsh);
		break;
	case 127:
		forr = get_not_found_error(cowsh);
		break;
	case 2:
		if (strcap_e("exit", cowsh->kwargs[0]) == 0)
			forr = get_exit_shell_error(cowsh);
		else if (strcap_e("cd", cowsh->kwargs[0]) == 0)
			forr = get_cd_error_message(cowsh);
		break;
	}

	if (forr)
	{
		write(STDERR_FILENO, forr, guru(forr));
		free(forr);
	}

	cowsh->guys = cat2;
	return (cat2);
}
