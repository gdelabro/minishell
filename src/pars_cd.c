/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_cd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 17:01:57 by gdelabro          #+#    #+#             */
/*   Updated: 2017/03/23 17:45:01 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		is_option(char *str)
{
	int i;

	i = 0;
	if (str[0] != '-' || !ft_strcmp("-", str))
		return (0);
	while (str[++i] && (str[i] == 'P' || str[i] == 'L'))
		;
	if (i == (int)ft_strlen(str))
		return (1);
	return (0);
}

void	option_p(t_cd *e)
{
	char		*tmp;
	char		*tmp2;
	struct stat	stat;

	lstat(e->dir, &stat);
	if (e->p == 1 && S_ISLNK(stat.st_mode))
	{
		!(tmp = (char*)malloc(sizeof(char) * 256)) ? exit(EXIT_FAILURE) : 0;
		ft_bzero(tmp, 256);
		readlink(e->dir, tmp, 256);
		tmp2 = e->dir[0] == '/' ? ft_strjoin("/", tmp) : ft_strdup(tmp);
		ft_strdel(&tmp);
		ft_strdel(&e->dir);
		e->dir = tmp2;
	}
}

int		find_dir(char *str, t_cd *e, char **g_env)
{
	char *tmp;
	char *tmp2;

	if (str[0] == '~' && (str[1] == '/' || !str[1]))
	{
		if (!(tmp2 = ft_getcontent("HOME", g_env)))
		{
			ft_putendl_fd("cd: error: HOME not set", 2);
			return (0);
		}
		tmp = ft_strsub(str, 1, ft_strlen(str) - 1);
		e->dir = ft_strjoin(tmp2, tmp);
		ft_strdel(&tmp2);
		ft_strdel(&tmp);
	}
	else if (!ft_strcmp("-", str))
	{
		e->dir = ft_getcontent("OLDPWD", g_env);
		!e->dir ? ft_putendl_fd("cd: OLDPWD not set", 2) : ft_putendl(e->dir);
		if (!e->dir)
			return (0);
	}
	else
		e->dir = ft_strdup(str);
	return (1);
}

int		pars_cd(char **tab, t_cd *e, char **g_env)
{
	int ret;

	e->l = 0;
	e->p = 0;
	e->i = 0;
	while (tab[++e->i])
	{
		if (is_option(tab[e->i]) == 1 && !(e->i2 = 0))
			while (tab[e->i][++e->i2])
				tab[e->i][e->i2] == 'P' ? e->p = 1 : 0;
		else
			break ;
	}
	if (tab[e->i])
	{
		ret = find_dir(tab[e->i], e, g_env);
		option_p(e);
		return (ret);
	}
	else
		return (find_dir("~", e, g_env));
	return (1);
}
