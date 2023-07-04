#include "main.h"

/**
 * generate_env_error - Generates the error message for env in get_env.
 * @datash: Relevant data (counter, arguments)
 * Return: Error message
 */
char *generate_env_error(data_shell *datash)
{
	int length;
	char *error;
	char *line_counter;
	char *msg;

	line_counter = aux_itoa(datash->counter);
	msg = ": Unable to add/remove from environment\n";
	length = _strlen(datash->av[0]) + _strlen(line_counter);
	length += _strlen(datash->args[0]) + _strlen(msg) + 4;
	error = malloc(sizeof(char) * (length + 1));
	if (error == NULL)
	{
		free(error);
		free(line_counter);
		return (NULL);
	}

	_strcpy(error, datash->av[0]);
	_strcat(error, ": ");
	_strcat(error, line_counter);
	_strcat(error, ": ");
	_strcat(error, datash->args[0]);
	_strcat(error, msg);
	_strcat(error, "\0");
	free(line_counter);

	return (error);
}

/**
 * generate_path_126_error - Generates the error message for
 * path and failure denied permission.
 * @datash: Relevant data (counter, arguments)
 * Return: Error message
 */
char *generate_path_126_error(data_shell *datash)
{
	int length;
	char *line_counter;
	char *error;

	line_counter = aux_itoa(datash->counter);
	length = _strlen(datash->av[0]) + _strlen(line_counter);
	length += _strlen(datash->args[0]) + 24;
	error = malloc(sizeof(char) * (length + 1));
	if (error == NULL)
	{
		free(error);
		free(line_counter);
		return (NULL);
	}
	_strcpy(error, datash->av[0]);
	_strcat(error, ": ");
	_strcat(error, line_counter);
	_strcat(error, ": ");
	_strcat(error, datash->args[0]);
	_strcat(error, ": Permission denied\n");
	_strcat(error, "\0");
	free(line_counter);
	return (error);
}

