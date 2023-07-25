#include "main.h"

/**
 * get_help - function that retrieves help messages according builtin
 * @datash: data structure (args and input)
 * Return: Return 0
*/
int get_help(data_shell *datash)
{

	if (datash->args[1] == 0)
		duo_color();
	else if (strcap_e(datash->args[1], "setenv") == 0)
		invert_color();
	else if (strcap_e(datash->args[1], "env") == 0)
		load_color();
	else if (strcap_e(datash->args[1], "unsetenv") == 0)
		lens_color();
	else if (strcap_e(datash->args[1], "help") == 0)
		help_info_builtin();
	else if (strcap_e(datash->args[1], "exit") == 0)
		saturn_color();
	else if (strcap_e(datash->args[1], "cd") == 0)
		help_info_cd();
	else if (strcap_e(datash->args[1], "alias") == 0)
		help_info_alias();
	else
		write(STDERR_FILENO, datash->args[0],
		      guru(datash->args[0]));

	datash->status = 0;
	return (1);
}
