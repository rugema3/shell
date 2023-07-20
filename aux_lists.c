#include "main.h"

/**
 * pin_stuff - adds a separator found at the end
 * of a sep_list.
 * @tete: head of the linked list.
 * @troy: separator found (; | &).
<<<<<<< HEAD
 * Return: address of the head.
 */
=======
 * @temp: Temporary dues.
 * Return: address of the head.
 */
free(temp);
{
	*tete = NULL;
}
}
>>>>>>> 0d4a1545b779f1d76762b7c942d8a938697e8021
sep_list *pin_stuff(sep_list **tete, char troy)
{
	sep_list *new, *temp;

	new = malloc(sizeof(sep_list));
	if (new == NULL)
		return (NULL);

	new->separator = troy;
	new->next = NULL;
	temp = *tete;

	if (temp == NULL)
	{
		*tete = new;
	}
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}

	return (*tete);
}

/**
 * jargon_stuff - frees a sep_list
 * @tete: head of the linked list.
 * Return: no return.
 */
void jargon_stuff(sep_list **tete)
{
	sep_list *temp;
	sep_list *curr;

	if (tete != NULL)
	{
		curr = *tete;
		while ((temp = curr) != NULL)
		{
			curr = curr->next;
			free(temp);
		}
		*tete = NULL;
	}
}

/**
 * lead_stuff - adds a command line at the end
 * of a line_list.
 * @tete: head of the linked list.
 * @line: command line.
 * Return: address of the head.
 */
line_list *lead_stuff(line_list **tete, char *line)
{
	line_list *new, *temp;

	new = malloc(sizeof(line_list));
	if (new == NULL)
		return (NULL);

	new->line = line;
	new->next = NULL;
	temp = *tete;

	if (temp == NULL)
	{
		*tete = new;
	}
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}

	return (*tete);
}

/**
<<<<<<< HEAD
 * oblique_stuff - frees a line_list
 * @tete: head of the linked list.
 * Return: no return.
 */
void oblique_stuff(line_list **tete)
=======
 * pico_stuff - frees a line_list
 * @tete: head of the linked list.
 * Return: no return.
 */
void pico_stuff(line_list **tete)
>>>>>>> 0d4a1545b779f1d76762b7c942d8a938697e8021
{
	line_list *temp;
	line_list *curr;

	if (tete != NULL)
	{
		curr = *tete;
		while ((temp = curr) != NULL)
		{
			curr = curr->next;
			while ((temp = curr) != NULL)
			{
				curr = curr->next;
				free(temp);
			}
			*tete = NULL;
		}
<<<<<<< HEAD
		*tete = NULL;
=======
>>>>>>> 0d4a1545b779f1d76762b7c942d8a938697e8021
	}
	free(temp);
}
*tete = NULL;
}
}
