#include "main.h"

/**
 * _dot - changes to the parent directory
 *
 * @rndsh: data relevant (environ)
 *
 * Return: no return
 */
void _dot(data_shell *rndsh)
{
	char pluk[PATH_MAX];
	char *dir, *cp_pluk, *cpright_pluk;

	getcwd(pluk, sizeof(pluk));
	cp_pluk = haut(pluk);
	set_env("OLDPWD", cp_pluk, rndsh);
	dir = rndsh->args[1];
	if (strcap_e(".", dir) == 0)
	{
		set_env("PWD", cp_pluk, rndsh);
		free(cp_pluk);
		return;
	}
	if (strcap_e("/", cp_pluk) == 0)
	{
		free(cp_pluk);
		return;
	}
	cpright_pluk = cp_pluk;
	rem_string(cpright_pluk);
	cpright_pluk = right(cpright_pluk, "/");
	if (cpright_pluk != NULL)
	{
		cpright_pluk = right(NULL, "\0");

		if (cpright_pluk != NULL)
			rem_string(cpright_pluk);
	}
	if (cpright_pluk != NULL)
	{
		chdir(cpright_pluk);
		set_env("PWD", cpright_pluk, rndsh);
	}
	else
	{
		chdir("/");
		set_env("PWD", "/", rndsh);
	}
	rndsh->status = 0;
	free(cp_pluk);
}

/**
 * dot_cmd - changes to a directory given
 * by the user
 *
 * @rndsh: data relevant (directories)
 * Return: no return
 */
void dot_cmd(data_shell *rndsh)
{
	char pluk[PATH_MAX];
	char *dir, *cp_pluk, *cp_dir;

	getcwd(pluk, sizeof(pluk));

	dir = rndsh->args[1];
	if (chdir(dir) == -1)
	{
		get_feel_error2(rndsh, 2);
		return;
	}

	cp_pluk = haut(pluk);
	set_env("OLDPWD", cp_pluk, rndsh);

	cp_dir = haut(dir);
	set_env("PWD", cp_dir, rndsh);

	free(cp_pluk);
	free(cp_dir);

	rndsh->status = 0;

	chdir(dir);
}

/**
 * previous_cmd - changes to the previous directory
 *
 * @rndsh: data relevant (environ)
 * Return: no return
 */
void previous_cmd(data_shell *rndsh)
{
	char pluk[PATH_MAX];
	char *p_pluk, *p_oldpluk, *cp_pluk, *cp_oldpluk;

	getcwd(pluk, sizeof(pluk));
	cp_pluk = haut(pluk);

	p_oldpluk = akirenv("OLDPWD", rndsh->evision);

	if (p_oldpluk == NULL)
		cp_oldpluk = cp_pluk;
	else
		cp_oldpluk = haut(p_oldpluk);

	set_env("OLDPWD", cp_pluk, rndsh);

	if (chdir(cp_oldpluk) == -1)
		set_env("PWD", cp_pluk, rndsh);
	else
		set_env("PWD", cp_oldpluk, rndsh);

	p_pluk = akirenv("PWD", rndsh->evision);

	write(STDOUT_FILENO, p_pluk, guru(p_pluk));
	write(STDOUT_FILENO, "\n", 1);

	free(cp_pluk);
	if (p_oldpluk)
		free(cp_oldpluk);

	rndsh->status = 0;

	chdir(p_pluk);
}

/**
 * home_to_cdr - changes to home directory
 *
 * @rndsh: data relevant (environ)
 * Return: no return
 */
void home_to_cdr(data_shell *rndsh)
{
	char *p_pluk, *home;
	char pluk[PATH_MAX];

	getcwd(pluk, sizeof(pluk));
	p_pluk = haut(pluk);

	home = akirenv("HOME", rndsh->evision);

	if (home == NULL)
	{
		set_env("OLDPWD", p_pluk, rndsh);
		free(p_pluk);
		return;
	}

	if (chdir(home) == -1)
	{
		get_feel_error2(rndsh, 2);
		free(p_pluk);
		return;
	}

	set_env("OLDPWD", p_pluk, rndsh);
	set_env("PWD", home, rndsh);
	free(p_pluk);
	rndsh->status = 0;
}
