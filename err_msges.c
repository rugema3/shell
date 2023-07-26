#include "main.h"

/**
 * concat_error_message - function that concatenates the message for cd error
 *
 * @rndsh: data relevant (directory)
 * @msg: message to print
 * @error: output message
 * @line_counter: counter lines
 * Return: error message
 */
char *concat_error_message(datacliff *rndsh, char *msg, char *error, char *line_counter)
{
	char *illegal_flag;

	_strap_y(error, rndsh->evr[0]);
	_strap_y(error, ": ");
	_strap_y(error, line_counter);
	_strap_y(error, ": ");
	_strap_y(error, rndsh->kwargs[0]);
	_strap_y(error, msg);
	if (rndsh->kwargs[1][0] == '-')
	{
		illegal_flag = malloc(3);
		illegal_flag[0] = '-';
		illegal_flag[1] = rndsh->kwargs[1][1];
		illegal_flag[2] = '\0';
		_strap_y(error, illegal_flag);
		free(illegal_flag);
	}
	else
	{
		_strap_y(error, rndsh->kwargs[1]);
	}

	_strap_y(error, "\n");
	_strap_y(error, "\0");
	return (error);
}

/**
 * get_cd_error_message - error message for cd command in get_cd
 * @rndsh: data relevant (directory)
 * Return: Error message
 */
char *get_cd_error_message(datacliff *rndsh)
{
	int length, len_id;
	char *error, *line_counter, *msg;

	line_counter = conv_num(rndsh->compteur);
	if (rndsh->kwargs[1][0] == '-')
	{
		msg = ": Illegal option ";
		len_id = 2;
	}
	else
	{
		msg = ": can't cd to ";

		len_id = guru(rndsh->kwargs[1]);
	}

	length = guru(rndsh->evr[0]) + guru(rndsh->kwargs[0]);
	length += guru(line_counter) + guru(msg) + len_id + 5;
	error = malloc(sizeof(char) * (length + 1));

	if (error == 0)
	{
		free(line_counter);
		return (NULL);
	}

	error = concat_error_message(rndsh, msg, error, line_counter);

	free(line_counter);

	return (error);
}

/**
 * get_not_found_error - generic error message for command not found
 * @rndsh: data relevant (counter, arguments)
 * Return: Error message
 */
char *get_not_found_error(datacliff *rndsh)
{
	int length;
	char *error;
	char *line_counter;

	line_counter = conv_num(rndsh->compteur);
	length = guru(rndsh->evr[0]) + guru(line_counter);
	length += guru(rndsh->kwargs[0]) + 16;
	error = malloc(sizeof(char) * (length + 1));
	if (error == 0)
	{
		free(error);
		free(line_counter);
		return (NULL);
	}
	_strap_y(error, rndsh->evr[0]);
	_strap_y(error, ": ");
	_strap_y(error, line_counter);
	_strap_y(error, ": ");
	_strap_y(error, rndsh->kwargs[0]);
	_strap_y(error, ": not found\n");
	_strap_y(error, "\0");
	free(line_counter);
	return (error);
}

/**
 * get_exit_shell_error - generic error message for exit in get_exit
 * @rndsh: data relevant (compteur, arguments)
 *
 * Return: Error message
 */
char *get_exit_shell_error(datacliff *rndsh)
{
	int length;
	char *error;
	char *line_counter;

	line_counter = conv_num(rndsh->compteur);
	length = guru(rndsh->evr[0]) + guru(line_counter);
	length += guru(rndsh->kwargs[0]) + guru(rndsh->kwargs[1]) + 23;
	error = malloc(sizeof(char) * (length + 1));
	if (error == 0)
	{
		free(line_counter);
		return (NULL);
	}
	_strap_y(error, rndsh->evr[0]);
	_strap_y(error, ": ");
	_strap_y(error, line_counter);
	_strap_y(error, ": ");
	_strap_y(error, rndsh->kwargs[0]);
	_strap_y(error, ": Illegal number: ");
	_strap_y(error, rndsh->kwargs[1]);
	_strap_y(error, "\n\0");
	free(line_counter);

	return (error);
}

