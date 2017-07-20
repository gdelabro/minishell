/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 17:46:56 by gdelabro          #+#    #+#             */
/*   Updated: 2017/03/26 17:53:29 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	change_env(char ***g_env, char **pwd_path, char *new_pwd)
{
	char *tmp;

	tmp = ft_strjoin("setenv OLDPWD ", *pwd_path);
	instruction(tmp, g_env);
	ft_strdel(&tmp);
	tmp = ft_strjoin("setenv PWD ", new_pwd);
	instruction(tmp, g_env);
	ft_strdel(&tmp);
	ft_strdel(pwd_path);
	*pwd_path = new_pwd;
}

void	add_to_path(char **path, char *path2)
{
	char *tmp;

	if ((*path)[ft_strlen(*path) - 1] != '/')
	{
		tmp = *path;
		*path = ft_strjoin(*path, "/");
		ft_strdel(&tmp);
	}
	tmp = *path;
	*path = ft_strjoin(*path, path2);
	ft_strdel(&tmp);
}

void	rem_to_path(char **path)
{
	int		i;
	char	*tmp;

	i = ft_strlen(*path);
	while (--i >= 0 && (*path)[i] != '/')
		;
	i = ft_strlen(*path) - (ft_strlen(*path) - i);
	tmp = ft_strnew(256);
	ft_strncpy(tmp, *path, i);
	if (!ft_strcmp(tmp, ""))
	{
		ft_strdel(&tmp);
		tmp = ft_strdup("/");
	}
	ft_strdel(path);
	*path = tmp;
}

char	*modif_path(char *pwd_path, char *dir)
{
	char	*new_path;
	char	**split_path;
	int		i;

	if ((dir[0] == '~' || dir[0] == '/'))
		return (ft_strdup(dir));
	new_path = ft_strdup(pwd_path);
	split_path = ft_strsplit(dir, '/');
	i = -1;
	while (split_path[++i])
	{
		if (!ft_strcmp(split_path[i], ".."))
			rem_to_path(&new_path);
		else if (!ft_strcmp(split_path[i], "."))
			;
		else
			add_to_path(&new_path, split_path[i]);
	}
	free_ancien(split_path);
	return (new_path);
}

int		cmd_cd(char **tab, char ***g_env)
{
	t_cd		e;
	static char	*pwd_path = 0;
	char		*tmp;

	if (!pwd_path && !(pwd_path = ft_getcontent("PWD", *g_env)))
	{
		pwd_path = ft_strnew(256);
		ft_bzero(pwd_path, 256);
		getcwd(pwd_path, 256);
	}
	if (!pars_cd(tab, &e, *g_env))
		return (0);
	tmp = e.dir;
	e.dir = modif_path(pwd_path, e.dir);
	ft_strdel(&tmp);
	if (chdir(e.dir))
	{
		ft_putstr_fd("cd: no such file or directory: ", 2);
		ft_putendl_fd(e.dir, 2);
		ft_strdel(&e.dir);
		return (0);
	}
	change_env(g_env, &pwd_path, e.dir);
	return (1);
}
