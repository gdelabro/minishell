/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 14:37:58 by gdelabro          #+#    #+#             */
/*   Updated: 2017/03/21 16:17:11 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;

	!(str = (char*)malloc(sizeof(*str) * size + 1)) ? exit(EXIT_FAILURE) : 0;
	if (str == NULL)
		return (NULL);
	if (!size)
		return (str);
	ft_bzero(str, size + 1);
	return (str);
}
