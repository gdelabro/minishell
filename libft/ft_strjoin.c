/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 16:07:56 by gdelabro          #+#    #+#             */
/*   Updated: 2017/03/21 16:16:04 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	size1;
	size_t	size2;

	size1 = 0;
	size2 = 0;
	s1 ? size1 = ft_strlen(s1) : 0;
	s2 ? size2 = ft_strlen(s2) : 0;
	!(str = malloc(size1 + size2 + 1)) ? exit(EXIT_FAILURE) : 0;
	if (!str)
		return (NULL);
	s1 ? ft_strcpy(str, s1) : 0;
	s2 ? ft_strcpy(&str[size1], s2) : 0;
	return (str);
}
