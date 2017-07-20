/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 13:27:56 by gdelabro          #+#    #+#             */
/*   Updated: 2017/03/21 20:15:48 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <dirent.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <signal.h>
# include <errno.h>
# include "libft/libft.h"

# define NONE			"\033[0m"
# define BOLD			"\033[1m"
# define BLACK			"\033[30m"
# define RED			"\033[31m"
# define RED_BOLD		"\033[31;1m"
# define GREEN			"\033[32;1m"
# define BROWN			"\033[33m"
# define YELLOW			"\033[33;1m"
# define BLUE			"\033[34m"
# define MAGENTA		"\033[35m"
# define CYAN			"\033[36;1m"
# define GRAY			"\033[37m"
# define DEV_C			"\033[43;34m"
# define DEV_B			"\033[46;34m"

typedef struct		s_cd
{
	int				l;
	int				p;
	char			*dir;
	int				i;
	int				i2;
	char			*tmp;
}					t_cd;

void				prompt(char **g_env);
void				instruction(char *line, char ***g_env);
char				**pars_space(char *line);
int					cmd_cd(char **tab, char ***g_env);
void				cmd_env(char **tab);
void				cmd_setenv(char **tab, char ***g_env);
void				cmd_unsetenv(char **tab, char ***g_env);
int					taille_tab(char **tab);
int					ft_getelem(char *elem, char **g_env);
int					pars_cd(char **tab, t_cd *e, char **g_env);
void				init_env(char ***g_env);
char				*ft_getcontent(char *elem, char **g_env);
int					lunch_cmd(char **tab, char **g_env);
void				cmd_echo(char **tab);
int					lunch_builtins(char **tab, char ***g_env);
void				pre_instruction(char *line, char ***g_env);
int					is_alpha(char *str);

#endif
