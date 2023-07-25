#include "main.h"

/**
 * colg - copies information between void pointers.
 * @str_grm: destination pointer.
 * @grm: source pointer.
 * @ingan: size of the new pointer.
 *
 * Return: no return.
 */
void colg(void *str_grm, const void *grm, unsigned int ingan)
{
	char *char_grm = (char *)grm;
	char *char_str_grm = (char *)str_grm;
	unsigned int j;

	for (j = 0; j < ingan; j++)
		char_str_grm[j] = char_grm[j];
}

/**
 * dem_realloc - reallocates a memory block.
 * @grm: pointer to the memory previously allocated.
 * @byte: size, in bytes, of the allocated space of grm.
 * @bytes: new size, in bytes, of the new memory block.
 *
 * Return: grm.
 * if bytes == byte, returns grm without changes.
 * if malloc fails, returns NULL.
 */
void *dem_realloc(void *grm, unsigned int byte, unsigned int bytes)
{
	void *str_grm;

	if (grm == NULL)
		return (malloc(bytes));

	if (bytes == 0)
	{
		free(grm);
		return (NULL);
	}

	if (bytes == byte)
		return (grm);

	str_grm = malloc(bytes);
	if (str_grm == NULL)
		return (NULL);

	if (bytes < byte)
		colg(str_grm, grm, bytes);
	else
		colg(str_grm, grm, byte);

	free(grm);
	return (str_grm);
}

/**
 * dem_realloc_m - reallocates a memory block of a double pointer.
 * @grm: double pointer to the memory previously allocated.
 * @byte: size, in bytes, of the allocated space of grm.
 * @bytes: new size, in bytes, of the new memory block.
 *
 * Return: grm.
 * if bytes == byte, returns grm without changes.
 * if malloc fails, returns NULL.
 */
char **dem_realloc_m(char **grm, unsigned int byte, unsigned int bytes)
{
	char **str_grm;
	unsigned int j;

	if (grm == NULL)
		return (malloc(sizeof(char *) * bytes));

	if (bytes == byte)
		return (grm);

	str_grm = malloc(sizeof(char *) * bytes);
	if (str_grm == NULL)
		return (NULL);

	for (j = 0; j < byte; j++)
		str_grm[j] = grm[j];

	free(grm);

	return (str_grm);
}
