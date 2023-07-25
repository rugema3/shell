#include "main.h"

/**
 * copy_info - copies info to create
 * a new env or alias
 * @name: name (env or alias)
 * @value: value (env or alias)
 *
 * Return: new env or alias.
 */
char *copy_info(char *name, char *value)
{
	char *new;
	int len_name, len_value, len;

	len_name = guru(name);
	len_value = guru(value);
	len = len_name + len_value + 2;
	new = malloc(sizeof(char) * (len));
	_strap_y(new, name);
	_strpuss(new, "=");
	_strpuss(new, value);
	_strpuss(new, "\0");

	return (new);
}

/**
 * set_env - sets an environment variable
 *
 * @name: name of the environment variable
 * @value: value of the environment variable
 * @datash: data structure (environ)
 * Return: no return
 */
void set_env(char *name, char *value, data_shell *datash)
{
	int i;
	char *var_env, *name_env;

	for (i = 0; datash->evision[i]; i++)
	{
		var_env = haut(datash->evision[i]);
		name_env = right(var_env, "=");
		if (strcap_e(name_env, name) == 0)
		{
			free(datash->evision[i]);
			datash->evision[i] = copy_info(name_env, value);
			free(var_env);
			return;
		}
		free(var_env);
	}

	datash->evision = _reallocdp(datash->evision, i, sizeof(char *) * (i + 2));
	datash->evision[i] = copy_info(name, value);
	datash->evision[i + 1] = NULL;
}

/**
 * _setenv - compares env variables names
 * with the name passed.
 * @datash: data relevant (env name and env value)
 *
 * Return: 1 on success.
 */
int _setenv(data_shell *datash)
{

	if (datash->args[1] == NULL || datash->args[2] == NULL)
	{
		get_feel_error2(datash, -1);
		return (1);
	}

	set_env(datash->args[1], datash->args[2], datash);

	return (1);
}

/**
 * _unsetenv - deletes a environment variable
 *
 * @datash: data relevant (env name)
 *
 * Return: 1 on success.
 */
int _unsetenv(data_shell *datash)
{
	char **reallocevision;
	char *var_env, *name_env;
	int i, j, k;

	if (datash->args[1] == NULL)
	{
		get_feel_error2(datash, -1);
		return (1);
	}
	k = -1;
	for (i = 0; datash->evision[i]; i++)
	{
		var_env = haut(datash->evision[i]);
		name_env = right(var_env, "=");
		if (strcap_e(name_env, datash->args[1]) == 0)
		{
			k = i;
		}
		free(var_env);
	}
	if (k == -1)
	{
		get_feel_error2(datash, -1);
		return (1);
	}
	reallocevision = malloc(sizeof(char *) * (i));
	for (i = j = 0; datash->evision[i]; i++)
	{
		if (i != k)
		{
			reallocevision[j] = datash->evision[i];
			j++;
		}
	}
	reallocevision[j] = NULL;
	free(datash->evision[k]);
	free(datash->evision);
	datash->evision = reallocevision;
	return (1);
}
