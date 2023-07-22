#include "main.h"

/**
 * _strxat - concatenate two strings
 * @best: char pointer the dest of the copied str
 * @srcm: const char pointer the source of str
 * Return: the dest
 */
char *_strxat(char *best, const char *srcm)
{
	int i;
	int j;

	for (i = 0; best[i] != '\0'; i++)
		;

	for (j = 0; srcm[j] != '\0'; j++)
	{
		best[i] = srcm[j];
		i++;
	}

	best[i] = '\0';
	return (best);
}
/**
 * *_strcp_y - Copies the string pointed to by src.
 * @best: Type char pointer the dest of the copied str
 * @srcm: Type char pointer the source of str
 * Return: the dest.
 */
char *_strcp_y(char *best, char *srcm)
{

	size_t y;

	for (y = 0; srcm[y] != '\0'; y++)
	{
		best[y] = srcm[y];
	}
	best[y] = '\0';

	return (best);
}
/**
 * strcmp_e - Function that compares two strings.
 * @b1: type str compared
 * @b2: type str compared
 * Return: Always 0.
 */
int strcmp_e(char *b1, char *b2)
{
	int i;

	for (i = 0; b1[i] == b2[i] && b1[i]; i++)
		;

	if (b1[i] > b2[i])
		return (1);
	if (b1[i] < b2[i])
		return (-1);
	return (0);
}
/**
 * strchr_load - locates a character in a string,
 * @b: string.
 * @d: character.
 * Return: the pointer to the first occurrence of the character c.
 */
char *strchr_load(char *b, char d)
{
	unsigned int i = 0;

	for (; *(b + i) != '\0'; i++)
		if (*(b + i) == d)
			return (b + i);
	if (*(b + i) == d)
		return (b + i);
	return ('\0');
}
/**
 * strspn_load - gets the length of a prefix substring.
 * @b: initial segment.
 * @except: accepted bytes.
 * Return: the number of accepted bytes.
 */
int strspn_load(char *b, char *except)
{
	int i, j, cool;

	for (i = 0; *(b + i) != '\0'; i++)
	{
		cool = 1;
		for (j = 0; *(except + j) != '\0'; j++)
		{
			if (*(b + i) == *(except + j))
			{
				cool = 0;
				break;
			}
		}
		if (cool == 1)
			break;
	}
	return (i);
}
