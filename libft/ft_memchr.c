/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 12:59:25 by gdelabro          #+#    #+#             */
/*   Updated: 2016/11/10 16:46:42 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s2;
	unsigned char	c2;

	c2 = (unsigned char)c;
	s2 = (unsigned char*)s;
	while (n)
	{
		if (*s2 == c2)
			return (s2);
		s2++;
		n--;
	}
	return (NULL);
}
