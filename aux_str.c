#include "main.h"

/**
 * _strpuss - concatenate two strings
 * @best: char pointer the dest of the copied str
 * @srcm: const char pointer the source of str
 * Return: the dest
 */
char *_strpuss(char *best, const char *srcm)
{
	int trop;
	int jik;

	for (trop = 0; best[trop] != '\0'; trop++)
		;

	for (jik = 0; srcm[jik] != '\0'; jik++)
	{
		best[trop] = srcm[jik];
		trop++;
	}

	best[trop] = '\0';
	return (best);
}
/**
 * *_strap_y - Copies the string pointed to by src.
 * @best: Type char pointer the dest of the copied str
 * @srcm: Type char pointer the source of str
 * Return: the dest.
 */
char *_strap_y(char *best, char *srcm)
{

	size_t a;

	for (a = 0; srcm[a] != '\0'; a++)
	{
		best[a] = srcm[a];
	}
	best[a] = '\0';

	return (best);
}
/**
 * strcap_e - Function that compares two strings.
 * @b1: type str compared
 * @b2: type str compared
 * Return: Always 0.
 */
int strcap_e(char *b1, char *b2)
{
	int trop;

	for (trop = 0; b1[trop] == b2[trop] && b1[trop]; trop++)
		;

	if (b1[trop] > b2[trop])
		return (1);
	if (b1[trop] < b2[trop])
		return (-1);
	return (0);
}
/**
 * strchrap_load - locates a character in a string,
 * @b: string.
 * @charac: character.
 * Return: the pointer to the first occurrence of the character c.
 */
char *strchrap_load(char *b, char charac)
{
	unsigned int trop = 0;

	for (; *(b + trop) != '\0'; trop++)
		if (*(b + trop) == charac)
			return (b + trop);
	if (*(b + trop) == charac)
		return (b + trop);
	return ('\0');
}
/**
 * strsnap_load - gets the length of a prefix substring.
 * @b: initial segment.
 * @expat: accepted bytes.
 * Return: the number of accepted bytes.
 */
int strsnap_load(char *b, char *expat)
{
	int trop, jik, bool;

	for (trop = 0; *(b + trop) != '\0'; trop++)
	{
		bool = 1;
		for (jik = 0; *(expat + jik) != '\0'; jik++)
		{
			if (*(b + trop) == *(expat + jik))
			{
				bool = 0;
				break;
			}
		}
		if (bool == 1)
			break;
	}
	return (trop);
}
