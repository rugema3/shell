#include "main.h"

/**
 * concat_error_message - function that concatenates the message for cd error
 *
 * @datash: data relevant (directory)
 * @msg: message to print
 * @error: output message
 * @line_counter: counter lines
 * Return: error message
 */
char *concat_error_message(data_shell *datash, char *msg, char *error, char *line_counter)
{
	char *illegal_flag;

	_strcpy(error, datash->av[0]);
	_strcat(error, ": ");
	_strcat(error, line_counter);
	_strcat(error, ": ");
	_strcat(error, datash->args[0]);
	_strcat(error, msg);
	if (datash->args[1][0] == '-')
	{
		illegal_flag = malloc(3);
		illegal_flag[0] = '-';
		illegal_flag[1] = datash->args[1][1];
		illegal_flag[2] = '\0';
		_strcat(error, illegal_flag);
		free(illegal_flag);
	}
	else
	{
		_strcat(error, datash->args[1]);
	}

	_strcat(error, "\n");
	_strcat(error, "\0");
	return (error);
}

/**
 * get_cd_error_message - error message for cd command in get_cd
 * @datash: data relevant (directory)
 * Return: Error message
 */
char *get_cd_error_message(data_shell *datash)
{
	int length, len_id;
	char *error, *line_counter, *msg;

	line_counter = conv_num(datash->counter);
	if (datash->args[1][0] == '-')
	{
		msg = ": Illegal option ";
		len_id = 2;
	}
	else
	{
		msg = ": can't cd to ";

		len_id = _strlen(datash->args[1]);
	}

	length = _strlen(datash->av[0]) + _strlen(datash->args[0]);
	length += _strlen(line_counter) + _strlen(msg) + len_id + 5;
	error = malloc(sizeof(char) * (length + 1));

	if (error == 0)
	{
		free(line_counter);
		return (NULL);
	}

	error = concat_error_message(datash, msg, error, line_counter);

	free(line_counter);

	return (error);
}

/**
 * get_not_found_error - generic error message for command not found
 * @datash: data relevant (counter, arguments)
 * Return: Error message
 */
char *get_not_found_error(data_shell *datash)
{
	int length;
	char *error;
	char *line_counter;

	line_counter = conv_num(datash->counter);
	length = _strlen(datash->av[0]) + _strlen(line_counter);
	length += _strlen(datash->args[0]) + 16;
	error = malloc(sizeof(char) * (length + 1));
	if (error == 0)
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
	_strcat(error, ": not found\n");
	_strcat(error, "\0");
	free(line_counter);
	return (error);
}

/**
 * get_exit_shell_error - generic error message for exit in get_exit
 * @datash: data relevant (counter, arguments)
 *
 * Return: Error message
 */
char *get_exit_shell_error(data_shell *datash)
{
	int length;
	char *error;
	char *line_counter;

	line_counter = conv_num(datash->counter);
	length = _strlen(datash->av[0]) + _strlen(line_counter);
	length += _strlen(datash->args[0]) + _strlen(datash->args[1]) + 23;
	error = malloc(sizeof(char) * (length + 1));
	if (error == 0)
	{
		free(line_counter);
		return (NULL);
	}
	_strcpy(error, datash->av[0]);
	_strcat(error, ": ");
	_strcat(error, line_counter);
	_strcat(error, ": ");
	_strcat(error, datash->args[0]);
	_strcat(error, ": Illegal number: ");
	_strcat(error, datash->args[1]);
	_strcat(error, "\n\0");
	free(line_counter);

	return (error);
}

