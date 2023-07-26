#include "main.h"

/**
 * exit_shell - exits the shell
 *
 * @datash: data relevant (status and args)
 * Return: 0 on success.
 */
int exit_shell(datacliff *datash)
{
	unsigned int ustatus;
	int is_digit;
	int str_len;
	int big_number;

	if (datash->kwargs[1] != NULL)
	{
		ustatus = str_oax(datash->kwargs[1]);
		is_digit = cnombre(datash->kwargs[1]);
		str_len = guru(datash->kwargs[1]);
		big_number = ustatus > (unsigned int)INT_MAX;
		if (!is_digit || str_len > 10 || big_number)
		{
			get_feel_error2(datash, 2);
			datash->guys = 2;
			return (1);
		}
		datash->guys = (ustatus % 256);
	}
	return (0);
}
