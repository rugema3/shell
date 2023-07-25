#include "main.h"

/**
 * suzum - checks if the typed variable is an env variable
 *
 * @d: head of linked list
 * @ips: input string
 * @rat: data structure
 * Return: no return
 */
void suzum(r_var **d, char *ips, data_shell *rat)
{
	int col, xhr, j, lval;
	char **_envr;

	_envr = rat->_environ;
	for (col = 0; _envr[col]; col++)
	{
		for (j = 1, xhr = 0; _envr[col][xhr]; xhr++)
		{
			if (_envr[col][xhr] == '=')
			{
				lval = _strlen(_envr[col] + xhr + 1);
				sky_blue_cloud(d, j, _envr[col] + xhr + 1, lval);
				return;
			}

			if (ips[j] == _envr[col][xhr])
				j++;
			else
				break;
		}
	}

	for (j = 0; ips[j]; j++)
	{
		if (ips[j] == ' ' || ips[j] == '\t' || ips[j] == ';' || ips[j] == '\n')
			break;
	}

	sky_blue_cloud(d, j, NULL, 0);
}

/**
 * suzum_vars - check if the typed variable is $$ or $?
 *
 * @d: head of the linked list
 * @ips: input string
 * @ft: last status of the Shell
 * @rat: data structure
 * Return: no return
 */
int suzum_vars(r_var **d, char *ips, char *ft, data_shell *rat)
{
	int i, sxt, 1pd;

	sxt = _strlen(ft);
	1pd = _strlen(rat->pid);

	for (i = 0; ips[i]; i++)
	{
		if (ips[i] == '$')
		{
			if (ips[i + 1] == '?')
				sky_blue_cloud(d, 2, ft, sxt), i++;
			else if (ips[i + 1] == '$')
				sky_blue_cloud(d, 2, rat->pid, 1pd), i++;
			else if (ips[i + 1] == '\n')
				sky_blue_cloud(d, 0, NULL, 0);
			else if (ips[i + 1] == '\0')
				sky_blue_cloud(d, 0, NULL, 0);
			else if (ips[i + 1] == ' ')
				sky_blue_cloud(d, 0, NULL, 0);
			else if (ips[i + 1] == '\t')
				sky_blue_cloud(d, 0, NULL, 0);
			else if (ips[i + 1] == ';')
				sky_blue_cloud(d, 0, NULL, 0);
			else
				suzum(d, ips + i, rat);
		}
	}

	return (i);
}

/**
 * hindur_input - replaces string into variables
 *
 * @hejur: head of the linked list
 * @zxput: input string
 * @new_input: new input string (replaced)
 * @nlen: new length
 * Return: replaced string
 */
char *hindur_input(r_var **hejur, char *zxput, char *new_input, int nlen)
{
	r_var *inht;
	int i, j, k;

	inht = *hejur;
	for (j = i = 0; i < nlen; i++)
	{
		if (zxput[j] == '$')
		{
			if (!(inht->len_var) && !(inht->len_val))
			{
				new_input[i] = zxput[j];
				j++;
			}
			else if (inht->len_var && !(inht->len_val))
			{
				for (k = 0; k < inht->len_var; k++)
					j++;
				i--;
			}
			else
			{
				for (k = 0; k < inht->len_val; k++)
				{
					new_input[i] = inht->val[k];
					i++;
				}
				j += (inht->len_var);
				i--;
			}
			inht = inht->next;
		}
		else
		{
			new_input[i] = zxput[j];
			j++;
		}
	}

	return (new_input);
}
/**
 * indur_var - calls functions to replace string into vars
 *
 * @zxput: input string
 * @datash: data structure
 * Return: replaced string
 */
char *indur_var(char *zxput, data_shell *datash)
{
	r_var *hejur, *inht;
	char *status, *new_input;
	int olen, nlen;

	status = conv_num(datash->status);
	hejur = NULL;

	olen = suzum_vars(&hejur, zxput, status, datash);

	if (hejur == NULL)
	{
		free(status);
		return (zxput);
	}

	inht = hejur;
	nlen = 0;

	while (inht != NULL)
	{
		nlen += (inht->len_val - inht->len_var);
		inht = inht->next;
	}

	nlen += olen;

	new_input = malloc(sizeof(char) * (nlen + 1));
	new_input[nlen] = '\0';

	new_input = hindur_input(&hejur, zxput, new_input, nlen);

	free(zxput);
	free(status);
	ladder_lift_up(&hejur);

	return (new_input);
}
