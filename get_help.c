#include "main.h"

/**
 * akir_ubuf - function that retrieves help messages according builtin
 * @rndsh: data structure (args and input)
 * Return: Return 0
*/
int akir_ubuf(data_shell *rndsh)
{

	if (rndsh->args[1] == 0)
		duo_color();
	else if (strcap_e(rndsh->args[1], "setenv") == 0)
		invert_color();
	else if (strcap_e(rndsh->args[1], "env") == 0)
		load_color();
	else if (strcap_e(rndsh->args[1], "unsetenv") == 0)
		lens_color();
	else if (strcap_e(rndsh->args[1], "help") == 0)
		help_info_builtin();
	else if (strcap_e(rndsh->args[1], "exit") == 0)
		saturn_color();
	else if (strcap_e(rndsh->args[1], "cd") == 0)
		help_info_cd();
	else if (strcap_e(rndsh->args[1], "alias") == 0)
		help_info_alias();
	else
		write(STDERR_FILENO, rndsh->args[0],
		      guru(rndsh->args[0]));

	rndsh->guys = 0;
	return (1);
}
