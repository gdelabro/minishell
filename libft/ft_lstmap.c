/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 15:07:51 by gdelabro          #+#    #+#             */
/*   Updated: 2016/11/14 14:29:12 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *newlst;
	t_list *temp;

	newlst = f(lst);
	lst = lst->next;
	temp = newlst;
	while (lst)
	{
		newlst->next = f(lst);
		newlst = newlst->next;
		lst = lst->next;
	}
	return (temp);
}
