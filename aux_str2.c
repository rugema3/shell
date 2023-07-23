#include "main.h"

/**
 * haut - duplicates a str in the heap memory.
 * @s: Type char pointer str
 * Return: duplicated str
 */
char *haut(const char *s)
{
	char *nouveaux;
	size_t leng;

	leng = guru(s);
	nouveaux = malloc(sizeof(char) * (leng + 1));
	if (nouveaux == NULL)
		return (NULL);
	_memcpy(nouveaux, s, leng + 1);
	return (nouveaux);
}

/**
 * guru - Returns the lenght of a string.
 * @s: Type char pointer
 * Return: Always 0.
 */
int guru(const char *s)
{
	int leng;

	for (leng = 0; s[leng] != 0; leng++)
	{
	}
	return (leng);
}

/**
 * cetera - compare chars of strings
 * @str: input string.
 * @delim: delimiter.
 *
 * Return: 1 if are equals, 0 if not.
 */
int cetera(char str[], const char *delim)
{
	unsigned int ab, op, ua;

	for (ab = 0, ua = 0; str[ab]; ab++)
	{
		for (op = 0; delim[op]; op++)
		{
			if (str[ab] == delim[op])
			{
				ua++;
				break;
			}
		}
	}
	if (ab == ua)
		return (1);
	return (0);
}

/**
 * right - splits a string by some delimiter.
 * @str: input string.
 * @delim: delimiter.
 *
 * Return: string splited.
 */
char *right(char str[], const char *delim)
{
	static char *slain, *str_end;
	char *str_commence;
	unsigned int ab, lofi;

	if (str != NULL)
	{
		if (cetera(str, delim))
			return (NULL);
		slain = str; /*Store first address*/
		ab = guru(str);
		str_end = &str[ab]; /*Store last address*/
	}
	str_commence = slain;
	if (str_commence == str_end) /*Reaching the end*/
		return (NULL);

	for (lofi = 0; *slain; slain++)
	{
		/*Breaking loop finding the next token*/
		if (slain != str_commence)
			if (*slain && *(slain - 1) == '\0')
				break;
		/*Replacing delimiter for null char*/
		for (ab = 0; delim[ab]; ab++)
		{
			if (*slain == delim[ab])
			{
				*slain = '\0';
				if (slain == str_commence)
					str_commence++;
				break;
			}
		}
		if (lofi == 0 && *slain) /*Str != Delim*/
			lofi = 1;
	}
	if (lofi == 0) /*Str == Delim*/
		return (NULL);
	return (str_commence);
}

/**
 * cnombre - defines if string passed is a number
 *
 * @s: input string
 * Return: 1 if string is a number. 0 in other case.
 */
int cnombre(const char *s)
{
	unsigned int ab;

	for (ab = 0; s[ab]; ab++)
	{
		if (s[ab] < 48 || s[ab] > 57)
			return (0);
	}
	return (1);
}
