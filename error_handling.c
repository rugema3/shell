#include "main.h"

/**
 * concat_error_message_cd - function that concatenates the message for cd error
 *
 * @data: data relevant (directory)
 * @msg: message to print
 * @error_msg: output message
 * @version_str: counter lines
 * Return: error message
 */
char *concat_error_message_cd(data_shell *data, char *msg, char *error_msg, char *version_str)
{
    char *illegal_flag;

    _strcpy(error_msg, data->av[0]);
    _strcat(error_msg, ": ");
    _strcat(error_msg, version_str);
    _strcat(error_msg, ": ");
    _strcat(error_msg, data->args[0]);
    _strcat(error_msg, msg);
    if (data->args[1][0] == '-')
    {
        illegal_flag = malloc(3);
        illegal_flag[0] = '-';
        illegal_flag[1] = data->args[1][1];
        illegal_flag[2] = '\0';
        _strcat(error_msg, illegal_flag);
        free(illegal_flag);
    }
    else
    {
        _strcat(error_msg, data->args[1]);
    }

    _strcat(error_msg, "\n");
    _strcat(error_msg, "\0");
    return (error_msg);
}

/**
 * error_get_cd - error message for cd command in get_cd
 * @data: data relevant (directory)
 * Return: Error message
 */
char *error_get_cd(data_shell *data)
{
    int length, len_id;
    char *error_msg, *version_str, *msg;

    version_str = aux_itoa(data->counter);
    if (data->args[1][0] == '-')
    {
        msg = ": Illegal option ";
        len_id = 2;
    }
    else
    {
        msg = ": can't cd to ";
        len_id = _strlen(data->args[1]);
    }

    length = _strlen(data->av[0]) + _strlen(data->args[0]);
    length += _strlen(version_str) + _strlen(msg) + len_id + 5;
    error_msg = malloc(sizeof(char) * (length + 1));

    if (error_msg == 0)
    {
        free(version_str);
        return (NULL);
    }

    error_msg = concat_error_message_cd(data, msg, error_msg, version_str);

    free(version_str);

    return (error_msg);
}

/**
 * error_not_found - generic error message for command not found
 * @data: data relevant (counter, arguments)
 * Return: Error message
 */
char *error_not_found(data_shell *data)
{
    int length;
    char *error_msg;
    char *version_str;

    version_str = aux_itoa(data->counter);
    length = _strlen(data->av[0]) + _strlen(version_str);
    length += _strlen(data->args[0]) + 16;
    error_msg = malloc(sizeof(char) * (length + 1));
    if (error_msg == 0)
    {
        free(error_msg);
        free(version_str);
        return (NULL);
    }
    _strcpy(error_msg, data->av[0]);
    _strcat(error_msg, ": ");
    _strcat(error_msg, version_str);
    _strcat(error_msg, ": ");
    _strcat(error_msg, data->args[0]);
    _strcat(error_msg, ": not found\n");
    _strcat(error_msg, "\0");
    free(version_str);
    return (error_msg);
}

/**
 * error_exit_shell - generic error message for exit in get_exit
 * @data: data relevant (counter, arguments)
 *
 * Return: Error message
 */
char *error_exit_shell(data_shell *data)
{
    int length;
    char *error_msg;
    char *version_str;

    version_str = aux_itoa(data->counter);
    length = _strlen(data->av[0]) + _strlen(version_str);
    length += _strlen(data->args[0]) + _strlen(data->args[1]) + 23;
    error_msg = malloc(sizeof(char) * (length + 1));
    if (error_msg == 0)
    {
        free(version_str);
        return (NULL);
    }
    _strcpy(error_msg, data->av[0]);
    _strcat(error_msg, ": ");
    _strcat(error_msg, version_str);
    _strcat(error_msg, ": ");
    _strcat(error_msg, data->args[0]);
    _strcat(error_msg, ": Illegal number: ");
    _strcat(error_msg, data->args[1]);
    _strcat(error_msg, "\n\0");
    free(version_str);
    return (error_msg);
}

