#include "main.h"

/**
 * generate_env_error - Generates the error message for env in get_env.
 * @datash: Relevant data (compteur, arguments)
 * Return: Error message
 */
char *generate_env_error(datacliff *datash)
{
	int length;
	char *error;
	char *line_counter;
	char *msg;

	line_counter = conv_num(datash->compteur);
	msg = ": Unable to add/remove from environment\n";
	length = guru(datash->evr[0]) + guru(line_counter);
	length += guru(datash->kwargs[0]) + guru(msg) + 4;
	error = malloc(sizeof(char) * (length + 1));
	if (error == NULL)
	{
		free(error);
		free(line_counter);
		return (NULL);
	}

	_strap_y(error, datash->evr[0]);
	_strap_y(error, ": ");
	_strap_y(error, line_counter);
	_strap_y(error, ": ");
	_strap_y(error, datash->kwargs[0]);
	_strap_y(error, msg);
	_strap_y(error, "\0");
	free(line_counter);

	return (error);
}

/**
 * generate_path_126_error - Generates the error message for
 * path and failure denied permission.
 * @datash: Relevant data (compteur, arguments)
 * Return: Error message
 */
char *generate_path_126_error(datacliff *datash)
{
	int length;
	char *line_counter;
	char *error;

	line_counter = conv_num(datash->compteur);
	length = guru(datash->evr[0]) + guru(line_counter);
	length += guru(datash->kwargs[0]) + 24;
	error = malloc(sizeof(char) * (length + 1));
	if (error == NULL)
	{
		free(error);
		free(line_counter);
		return (NULL);
	}
	_strap_y(error, datash->evr[0]);
	_strap_y(error, ": ");
	_strap_y(error, line_counter);
	_strap_y(error, ": ");
	_strap_y(error, datash->kwargs[0]);
	_strap_y(error, ": Permission denied\n");
	_strap_y(error, "\0");
	free(line_counter);
	return (error);
}

