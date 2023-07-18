#include "main.h"

/**
 * load_color - Help information for the builtin env
 * Return: no return
 */
void load_color(void)
{
	char *mfasha = "env: env [option] [name=value] [command [args]]\n\t";

	write(STDOUT_FILENO, mfasha, _strlen(mfasha));
	mfasha = "Print the enviroment of the shell.\n";
	write(STDOUT_FILENO, mfasha, _strlen(mfasha));

}
/**
 * invert_color - Help information for the builtin setenv
 * Return: no return
 */
void invert_color(void)
{

	char *mfasha = "setenv: setenv (const char *name, const char *value,";

	write(STDOUT_FILENO, mfasha, _strlen(mfasha));
	mfasha = "int replace)\n\t";
	write(STDOUT_FILENO, mfasha, _strlen(mfasha));
	mfasha = "Add a new definition to the environment\n";
	write(STDOUT_FILENO, mfasha, _strlen(mfasha));
}
/**
 * lens_color - Help information for the builtin unsetenv
 * Return: no return
 */
void lens_color(void)
{
	char *mfasha = "unsetenv: unsetenv (const char *name)\n\t";

	write(STDOUT_FILENO, mfasha, _strlen(mfasha));
	mfasha = "Remove an entry completely from the environment\n";
	write(STDOUT_FILENO, mfasha, _strlen(mfasha));
}


/**
 * duo_color - Entry point for help information for the help builtin
 * Return: no return
 */
void duo_color(void)
{
	char *mfasha = "^-^ bash, version 1.0(1)-release\n";

	write(STDOUT_FILENO, mfasha, _strlen(mfasha));
	mfasha = "These commands are defined internally.Type 'help' to see the list";
	write(STDOUT_FILENO, mfasha, _strlen(mfasha));
	mfasha = "Type 'help name' to find out more about the function 'name'.\n\n ";
	write(STDOUT_FILENO, mfasha, _strlen(mfasha));
	mfasha = " alias: alias [name=['string']]\n cd: cd [-L|[-P [-e]] [-@]] ";
	write(STDOUT_FILENO, mfasha, _strlen(mfasha));
	mfasha = "[dir]\nexit: exit [n]\n  env: env [option] [name=value] [command ";
	write(STDOUT_FILENO, mfasha, _strlen(mfasha));
	mfasha = "[args]]\n  setenv: setenv [variable] [value]\n  unsetenv: ";
	write(STDOUT_FILENO, mfasha, _strlen(mfasha));
	mfasha = "unsetenv [variable]\n";
	write(STDOUT_FILENO, mfasha, _strlen(mfasha));
}
/**
 * saturn_color - Help information fot the builint exit
 * Return: no return
 */
void saturn_color(void)
{
	char *mfasha = "exit: exit [n]\n Exit shell.\n";

	write(STDOUT_FILENO, mfasha, _strlen(mfasha));
	mfasha = "Exits the shell with a status of N. If N is ommited, the exit";
	write(STDOUT_FILENO, mfasha, _strlen(mfasha));
	mfasha = "statusis that of the last command executed\n";
	write(STDOUT_FILENO, mfasha, _strlen(mfasha));
}
