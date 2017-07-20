/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 17:45:32 by gdelabro          #+#    #+#             */
/*   Updated: 2017/03/27 15:27:44 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	change_shlvl(char ***g_env)
{
	int		shlvl;
	char	*s;
	char	*tmp;
	char	*tmp2;

	if ((s = ft_getcontent("SHLVL", *g_env)))
	{
		shlvl = ft_atoi(s);
		tmp = ft_itoa(++shlvl);
		tmp2 = ft_strjoin("setenv SHLVL ", tmp);
		instruction(tmp2, g_env);
		ft_strdel(&s);
		ft_strdel(&tmp);
		ft_strdel(&tmp2);
	}
	else
		instruction("setenv SHLVL 2", g_env);
}

void	ctrl_c(int signo)
{
	char **env;

	(void)signo;
	env = ft_strsplit("LOGNAME=gdelabro", ' ');
	ft_putendl("");
	prompt(env);
	free_ancien(env);
}

void	ctrl_c2(int signo)
{
	(void)signo;
	ft_putendl("");
}

int		main(void)
{
	extern char		**environ;
	char			**g_env;
	char			*line;
	int				ret;

	!(g_env = cpy_tab(environ))[0] ? init_env(&g_env) : (change_shlvl(&g_env));
	instruction("cd .", &g_env);
	prompt(g_env);
	while (0xfeed)
	{
		signal(SIGINT, ctrl_c);
		ret = get_next_line(0, &line);
		if (ret > 0)
		{
			signal(SIGINT, ctrl_c2);
			pre_instruction(line, &g_env);
			prompt(g_env);
		}
		else if (ret == -1)
		{
			ft_putendl("");
			exit(1);
		}
		ft_strdel(&line);
	}
}
