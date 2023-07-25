#include "main.h"

/**
 * soma_umur - reads the input string.
 *
 * @toe_s: return value of getline function
 * Return: input string
 */
char *soma_umur(int *toe_s)
{
	char *zxput = NULL;
	size_t dufign = 0;

	*toe_s = getline(&zxput, &dufign, stdin);

	return (zxput);
}
