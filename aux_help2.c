#include "main.h"

/**
 * help_info_builtin - Help information for the builtin help.
 * Return: no return
 */
void help_info_builtin(void)
{
	char *help_str = "help: help [-dms] [pattern ...]\n";

	write(STDOUT_FILENO, help_str, _strlen(help_str));
	help_str = "\tDisplay information about builtin commands.\n ";
	write(STDOUT_FILENO, help_str, _strlen(help_str));
	help_str = "Displays brief summaries of builtin commands.\n";
	write(STDOUT_FILENO, help_str, _strlen(help_str));
}
/**
 * help_info_alias - Help information for the builtin alias.
 * Return: no return
 */
void help_info_alias(void)
{
	char *help_str = "alias: alias [-p] [name[=value]...]\n";

	write(STDOUT_FILENO, help_str, _strlen(help_str));
	help_str = "\tDefine or display aliases.\n ";
	write(STDOUT_FILENO, help_str, _strlen(help_str));
}
/**
 * help_info_cd - Help information for the builtin alias.
 * Return: no return
 */
void help_info_cd(void)
{
	char *help_str = "cd: cd [-L|[-P [-e]] [-@]] [dir]\n";

	write(STDOUT_FILENO, help_str, _strlen(help_str));
	help_str = "\tChange the shell working directory.\n ";
	write(STDOUT_FILENO, help_str, _strlen(help_str));
}
