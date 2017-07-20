/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   curseur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 17:33:31 by gdelabro          #+#    #+#             */
/*   Updated: 2017/03/26 17:55:51 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	init_env(char ***g_env)
{
	char	*tmp;
	char	*name;

	!(name = (char*)malloc(sizeof(char) * 256)) ? exit(EXIT_FAILURE) : 0;
	ft_bzero(name, 256);
	getcwd(name, 256);
	if (!ft_strcmp("", name))
	{
		ft_strdel(&name);
		name = ft_strdup("/");
	}
	tmp = ft_strjoin("setenv PWD ", name);
	instruction(tmp, g_env);
	instruction("setenv SHLVL 1", g_env);
	instruction("setenv SHELL ./minishell", g_env);
	instruction("setenv PATH /bin:/usr/bin", g_env);
	instruction("setenv _ /usr/bin/env", g_env);
	instruction("setenv LOGNAME gdelabro", g_env);
	ft_strdel(&tmp);
	ft_strdel(&name);
}

void	prompt(char **g_env)
{
	char	*name;
	char	*tmp;
	int		i;

	i = 0;
	if (!(name = ft_getcontent("PWD", g_env)))
	{
		i = 1;
		!(name = (char*)malloc(sizeof(char) * 256)) ? exit(EXIT_FAILURE) : 0;
		ft_bzero(name, 256);
		getcwd(name, 256);
	}
	ft_putstr(GREEN);
	tmp = ft_getcontent("LOGNAME", g_env);
	ft_putstr(tmp ? tmp : "undef");
	ft_putstr(" ");
	!i ? ft_putstr(NONE) : ft_putstr(RED);
	ft_putstr(name);
	ft_putstr(NONE);
	ft_putstr(" > ");
	ft_strdel(&name);
	if (tmp)
		ft_strdel(&tmp);
}
