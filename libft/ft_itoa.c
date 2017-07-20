/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 12:46:35 by gdelabro          #+#    #+#             */
/*   Updated: 2017/03/21 16:10:34 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_convert(char *str, long nb, int i, int neg)
{
	str[i--] = 0;
	if (neg == 1)
	{
		str[0] = '-';
		nb *= -1;
	}
	if (!nb)
		str = "0";
	while (nb)
	{
		str[i] = (nb % 10) + 48;
		i--;
		nb /= 10;
	}
	return (str);
}

char			*ft_itoa(int n)
{
	int		i;
	long	i2;
	int		neg;
	char	*str;

	if (n == 0)
	{
		!(str = (char*)malloc(sizeof(str) * 2)) ? exit(EXIT_FAILURE) : 0;
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	i2 = (long)n;
	i = 0;
	neg = 0;
	n <= 0 ? neg = 1 : 0;
	while (n && i++ > -1)
		n /= 10;
	!(str = (char*)malloc(sizeof(*str) * (i + neg + 1))) ?
		exit(EXIT_FAILURE) : 0;
	if (!str)
		return (NULL);
	return (ft_convert(str, i2, i + neg, neg));
}
