#include "main.h"

/**
 * sky_blue_cloud - adds a variable at the end
 * of a qr_var list.
 * @tete: head of the linked list.
 * @test_me: length of the variable.
 * @blopval: value of the variable.
 * @lift_me: length of the value.
 * Return: address of the head.
 */
qr_var *sky_blue_cloud(qr_var **tete, int test_me, char *blopval, int lift_me)
{
	qr_var *new, *temp;

	new = malloc(sizeof(qr_var));
	if (new == NULL)
		return (NULL);

	new->blop_var = test_me;
	new->blopval = blopval;
	new->blop_val = lift_me;

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
 * ladder_lift_up - frees a qr_var list
 * @tete: head of the linked list.
 * Return: no return.
 */
void ladder_lift_up(qr_var **tete)
{
	qr_var *temp;
	qr_var *curr;

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
