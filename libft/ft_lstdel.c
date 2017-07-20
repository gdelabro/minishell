/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 14:44:39 by gdelabro          #+#    #+#             */
/*   Updated: 2016/11/14 14:43:24 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *lst;
	t_list *nxt;

	lst = *alst;
	while (lst != NULL)
	{
		nxt = lst->next;
		del(lst->content, lst->content_size);
		free(lst);
		lst = NULL;
		lst = nxt;
	}
	*alst = NULL;
}
