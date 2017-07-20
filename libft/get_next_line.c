/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 13:42:41 by gdelabro          #+#    #+#             */
/*   Updated: 2017/03/15 19:17:35 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strclen(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s && s[i] && s[i] != c)
		++i;
	return (i);
}

static int		ft_fillbuf(const int fd, char **line)
{
	t_fl	fl;
	char	*tmp;

	fl.ret = 1;
	while (fl.ret && (!*line || (*line && !ft_strchr(*line, '\n'))))
	{
		fl.ret = read(fd, fl.buf, BUFF_SIZE);
		if (fl.ret < 0)
			return (fl.ret);
		fl.buf[fl.ret] = '\0';
		tmp = *line;
		*line = ft_strjoin(tmp, fl.buf);
		free(tmp);
		if (!ft_strchr(*line, '\n') && fl.ret != BUFF_SIZE)
			return (-1);
	}
	return (fl.ret);
}

static t_list	*ft_lstmove(t_list **lst, int fd)
{
	t_list		*tmp;

	tmp = *lst;
	if (!*lst)
	{
		*lst = ft_lstnew(NULL, 0);
		(*lst)->content_size = fd;
	}
	while (tmp && (int)tmp->content_size != fd)
	{
		tmp = tmp->next;
	}
	if (!tmp)
	{
		tmp = ft_lstnew(NULL, 0);
		tmp->content_size = fd;
		ft_lstadd(lst, tmp);
	}
	return (tmp);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*lst = NULL;
	t_list			*tmp;
	t_str			s;
	int				ret;

	tmp = ft_lstmove(&lst, fd);
	if (fd < 0 || !line || !tmp || BUFF_SIZE <= 0)
		return (-1);
	ret = ft_fillbuf(fd, (char **)&(tmp->content));
	if (!tmp->content || ret < 0)
		return (-1);
	s.p_str = ft_strchr((char*)tmp->content, '\n');
	s.len = ft_strclen((char *)tmp->content, '\n');
	s.p_str = ((char *)tmp->content + s.len);
	*s.p_str = '\0';
	ret > 0 ? s.p_str++ : 0;
	(s.ret_str = ft_strdup((char *)tmp->content)) ?
		*line = s.ret_str : 0;
	s.new_str = ft_strdup(s.p_str);
	tmp->content ? free((char *)tmp->content) : 0;
	tmp->content = s.new_str;
	if (ret || **line)
		return (1);
	return (0);
}
