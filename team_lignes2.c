#include "main.h"

/**
 * sky_blue_cloud - adds a variable at the end
 * of a qr_var list.
 * @tete: head of the linked list.
 * @test_me: length of the variable.
 * @val: value of the variable.
 * @lift_me: length of the value.
 * Return: address of the head.
 */
qr_var *sky_blue_cloud(qr_var **tete, int test_me, char *val, int lift_me)
{
	qr_var *new, *temp;

	new = malloc(sizeof(qr_var));
	if (new == NULL)
		return (NULL);

	new->len_var = test_me;
	new->val = val;
	new->len_val = lift_me;

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
			curr = curr->next;
			free(temp);
		}
		*tete = NULL;
	}
}
