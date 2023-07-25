#include "main.h"

/**
 * rem_string - reverses a string.
 * @d: input string.
 * Return: no return.
 */
void rem_string(char *d)
{
	int coumt = 0, i, j;
	char *ctr, tempe;

	while (coumt >= 0)
	{
		if (d[coumt] == '\0')
			break;
		coumt++;
	}
	ctr = d;

	for (i = 0; i < (coumt - 1); i++)
	{
		for (j = i + 1; j > 0; j--)
		{
			tempe = *(ctr + j);
			*(ctr + j) = *(ctr + (j - 1));
			*(ctr + (j - 1)) = tempe;
		}
	}
}
