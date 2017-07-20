/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lunch.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 15:07:00 by gdelabro          #+#    #+#             */
/*   Updated: 2017/03/21 17:12:28 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		lunch_builtins(char **tab, char ***g_env)
{
	if (!ft_strcmp("cd", tab[0]))
		cmd_cd(tab, g_env);
	else if (!ft_strcmp(tab[0], "exit"))
	{
		ft_putendl("exit");
		exit(0);
	}
	else if (!ft_strcmp(tab[0], "env"))
		cmd_env(*g_env);
	else if (!ft_strcmp(tab[0], "setenv"))
		cmd_setenv(tab, g_env);
	else if (!ft_strcmp(tab[0], "unsetenv"))
		cmd_unsetenv(tab, g_env);
	else if (!ft_strcmp(tab[0], "echo"))
		cmd_echo(tab);
	else if (!ft_strcmp(tab[0], "a"))
		pre_instruction("setenv _ dqw ; env", g_env);
	else
		return (lunch_cmd(tab, *g_env));
	return (1);
}

int		lunch_cmd3(char **tab, char **g_env)
{
	pid_t	father;
	int		ok;
	int		i;

	i = -1;
	ok = 0;
	while (tab[0][++i])
		tab[0][i] == '/' ? ok = 1 : 0;
	if (ok && !access(tab[0], 0))
	{
		father = fork();
		if (father)
			wait(&father);
		else
			execve(tab[0], tab, g_env) == -1 ? exit(1) : 0;
		return (1);
	}
	return (0);
}

int		lunch_cmd2(char **tab, char **tmp, char **g_env)
{
	pid_t	father;
	char	*prog;
	char	*prog2;
	int		i;

	i = -1;
	while (tmp && tmp[++i])
	{
		prog2 = ft_strjoin(tmp[i], "/");
		if ((prog = ft_strjoin(prog2, tab[0])) && !access(prog, 0))
		{
			if ((father = fork()))
				wait(&father);
			else
				execve(prog, tab, g_env) == -1 ? exit(1) : 0;
			ft_strdel(&prog);
			ft_strdel(&prog2);
			return (1);
		}
		ft_strdel(&prog2);
		ft_strdel(&prog);
	}
	return (0);
}

int		lunch_cmd(char **tab, char **g_env)
{
	char	**tmp;
	char	*name;
	int		i;

	name = ft_getcontent("PATH", g_env);
	tmp = ft_strsplit(name, ':');
	if (!lunch_cmd2(tab, tmp, g_env) && !lunch_cmd3(tab, g_env))
	{
		ft_putstr_fd("msh: command not found: ", 2);
		ft_putendl_fd(tab[0], 2);
		i = -1;
		while (tmp && tmp[++i])
			ft_strdel(&tmp[i]);
		tmp ? free(tmp) : 0;
		tmp ? tmp = NULL : 0;
		name ? ft_strdel(&name) : 0;
		return (0);
	}
	i = -1;
	while (tmp && tmp[++i])
		ft_strdel(&tmp[i]);
	tmp ? free(tmp) : 0;
	tmp ? tmp = NULL : 0;
	name ? ft_strdel(&name) : 0;
	return (1);
}
