/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 12:08:13 by gdelabro          #+#    #+#             */
/*   Updated: 2017/01/04 20:34:15 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char *a;
	char *b;

	if (!n || dest == src)
		return (dest);
	a = (char *)dest;
	b = (char *)src;
	while (n)
	{
		*a = *b;
		a++;
		b++;
		n--;
	}
	return (dest);
}
