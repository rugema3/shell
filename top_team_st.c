#include "main.h"

/**
 * how_long - Get the lenght of a number.
 * @num_it: type int number.
 * Return: Lenght of a number.
 */
int how_long(int num_it)
{
	unsigned int quant;
	int longeur = 1;

	if (num_it < 0)
	{
		longeur++;
		quant = num_it * -1;
	}
	else
	{
		quant = num_it;
	}
	while (quant > 9)
	{
		longeur++;
		quant = quant / 10;
	}

	return (longeur);
}
/**
 * conv_num - function converts int to string.
 * @num_it: type int number
 * Return: String.
 */
char *conv_num(int num_it)
{
	unsigned int quant;
	int longeur = how_long(num_it);
	char *lockerd;

	lockerd = malloc(sizeof(char) * (longeur + 1));
	if (lockerd == 0)
		return (NULL);

	*(lockerd + longeur) = '\0';

	if (num_it < 0)
	{
		quant = num_it * -1;
		lockerd[0] = '-';
	}
	else
	{
		quant = num_it;
	}

	longeur--;
	do {
		*(lockerd + longeur) = (quant % 10) + '0';
		quant = quant / 10;
		longeur--;
	}
	while (quant > 0)
		;
	return (lockerd);
}

/**
 * str_oax - converts a string to an integer.
 * @s: input string.
 * Return: integer.
 */
int str_oax(char *s)
{
	unsigned int compte = 0, la_taille = 0, inn = 0, rally = 1, quack = 1, i;

	while (*(s + compte) != '\0')
	{
		if (la_taille > 0 && (*(s + compte) < '0' || *(s + compte) > '9'))
			break;

		if (*(s + compte) == '-')
			rally *= -1;

		if ((*(s + compte) >= '0') && (*(s + compte) <= '9'))
		{
			if (la_taille > 0)
				quack *= 10;
			la_taille++;
		}
		compte++;
	}

	for (i = compte - la_taille; i < compte; i++)
	{
		inn = inn + ((*(s + i) - 48) * quack);
		quack /= 10;
	}
	return (inn * rally);
}
