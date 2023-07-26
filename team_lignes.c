#include "main.h"

/**
 * pin_stuff - adds a separator found at the end
 * of a blame_lists.
 * @tete: head of the linked list.
 * @troy: separator found (; | &).
 * Return: address of the head.
 */
blame_lists *pin_stuff(blame_lists **tete, char troy)
{
	blame_lists *new, *temp;

	new = malloc(sizeof(blame_lists));
	if (new == NULL)
		return (NULL);

	new->separateur = troy;
	new->suivant = NULL;
	temp = *tete;

	if (temp == NULL)
	{
		*tete = new;
	}
	else
	{
		while (temp->suivant != NULL)
			temp = temp->suivant;
		temp->suivant = new;
	}

	return (*tete);
}

/**
 * jargon_stuff - frees a blame_lists
 * @tete: head of the linked list.
 * Return: no return.
 */
void jargon_stuff(blame_lists **tete)
{
	blame_lists *temp;
	blame_lists *curr;

	if (tete != NULL)
	{
		curr = *tete;
		while ((temp = curr) != NULL)
		{
			curr = curr->suivant;
			free(temp);
		}
		*tete = NULL;
	}
}

/**
 * lead_stuff - adds a command line at the end
 * of a ligna_lista.
 * @tete: head of the linked list.
 * @ligna: command line.
 * Return: address of the head.
 */
ligna_lista *lead_stuff(ligna_lista **tete, char *ligna)
{
	ligna_lista *new, *temp;

	new = malloc(sizeof(ligna_lista));
	if (new == NULL)
		return (NULL);

	new->ligna = ligna;
	new->suivant = NULL;
	temp = *tete;

	if (temp == NULL)
	{
		*tete = new;
	}
	else
	{
		while (temp->suivant != NULL)
			temp = temp->suivant;
		temp->suivant = new;
	}

	return (*tete);
}

/**
 * oblique_stuff - frees a ligna_lista
 * @tete: head of the linked list.
 * Return: no return.
 */
void oblique_stuff(ligna_lista **tete)
{
	ligna_lista *temp;
	ligna_lista *curr;

	if (tete != NULL)
	{
		curr = *tete;
		while ((temp = curr) != NULL)
		{
			curr = curr->suivant;
			free(temp);
		}
		*tete = NULL;
	}
}
