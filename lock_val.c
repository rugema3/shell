#include "main.h"

/**
 * suzum_env - checks if the typed variable is an env variable
 *
 * @d: head of linked list
 * @ips: input string
 * @rat: data structure
 * Return: no return
 */
void suzum_env(qr_var **d, char *ips, datacliff *rat)
{
	int umurongo, xhr, j, uburo;
	char **_envr;

	_envr = rat->evision;
	for (umurongo = 0; _envr[umurongo]; umurongo++)
	{
		for (j = 1, xhr = 0; _envr[umurongo][xhr]; xhr++)
		{
			if (_envr[umurongo][xhr] == '=')
			{
				uburo = guru(_envr[umurongo] + xhr + 1);
				sky_blue_cloud(d, j, _envr[umurongo] + xhr + 1, uburo);
				return;
			}

			if (ips[j] == _envr[umurongo][xhr])
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
 * @foot: last status of the Shell
 * @rat: data structure
 * Return: no return
 */
int suzum_vars(qr_var **d, char *ips, char *foot, datacliff *rat)
{
	int i, sxt, lpd;

	sxt = guru(foot);
	lpd = guru(rat->id_pid);

	for (i = 0; ips[i]; i++)
	{
		if (ips[i] == '$')
		{
			if (ips[i + 1] == '?')
				sky_blue_cloud(d, 2, foot, sxt), i++;
			else if (ips[i + 1] == '$')
				sky_blue_cloud(d, 2, rat->id_pid, lpd), i++;
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
				suzum_env(d, ips + i, rat);
		}
	}

	return (i);
}

/**
 * hindur_input - replaces string into variables
 *
 * @hejur: head of the linked list
 * @zxput: input string
 * @new_zxput: new input string (replaced)
 * @rlen: new length
 * Return: replaced string
 */
char *hindur_input(qr_var **hejur, char *zxput, char *new_zxput, int rlen)
{
	qr_var *inht;
	int i, j, k;

	inht = *hejur;
	for (j = i = 0; i < rlen; i++)
	{
		if (zxput[j] == '$')
		{
			if (!(inht->blop_var) && !(inht->blop_val))
			{
				new_zxput[i] = zxput[j];
				j++;
			}
			else if (inht->blop_var && !(inht->blop_val))
			{
				for (k = 0; k < inht->blop_var; k++)
					j++;
				i--;
			}
			else
			{
				for (k = 0; k < inht->blop_val; k++)
				{
					new_zxput[i] = inht->blopval[k];
					i++;
				}
				j += (inht->blop_var);
				i--;
			}
			inht = inht->suivant;
		}
		else
		{
			new_zxput[i] = zxput[j];
			j++;
		}
	}

	return (new_zxput);
}

/**
 * indur_var - calls functions to replace string into vars
 *
 * @zxput: input string
 * @rndsh: data structure
 * Return: replaced string
 */
char *indur_var(char *zxput, datacliff *rndsh)
{
	qr_var *hejur, *inht;
	char *guys, *new_zxput;
	int blen, rlen;

	guys = conv_num(rndsh->guys);
	hejur = NULL;

	blen = suzum_vars(&hejur, zxput, guys, rndsh);

	if (hejur == NULL)
	{
		free(guys);
		return (zxput);
	}

	inht = hejur;
	rlen = 0;

	while (inht != NULL)
	{
		rlen += (inht->blop_val - inht->blop_var);
		inht = inht->suivant;
	}

	rlen += blen;

	new_zxput = malloc(sizeof(char) * (rlen + 1));
	new_zxput[rlen] = '\0';

	new_zxput = hindur_input(&hejur, zxput, new_zxput, rlen);

	free(zxput);
	free(guys);
	ladder_lift_up(&hejur);

	return (new_zxput);
}
