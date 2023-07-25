#include "main.h"

/**
 * sky_blue_cloud - adds a variable at the end
 * of a r_var list.
 * @tete: head of the linked list.
 * @test_me: length of the variable.
 * @val: value of the variable.
 * @lift_me: length of the value.
 * Return: address of the head.
 */
r_var *sky_blue_cloud(r_var **tete, int test_me, char *val, int lift_me)
{
	r_var *new, *temp;

	new = malloc(sizeof(r_var));
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
 * ladder_lift_up - frees a r_var list
 * @tete: head of the linked list.
 * Return: no return.
 */
void ladder_lift_up(r_var **tete)
{
	r_var *temp;
	r_var *curr;

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
