/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulopez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 08:37:57 by aulopez           #+#    #+#             */
/*   Updated: 2018/11/13 14:45:19 by aulopez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	char *buf;

	buf = s1;
	while (*s1)
		s1++;
	while (*s2)
		*(s1++) = *(s2++);
	*s1 = '\0';
	return (buf);
}
/*
char	*ft_strcat(char *s1, const char *s2)
{
	size_t	i;

	i = ft_strlen(s1);
	ft_memccpy(s1 + i, s2, 0, -1);
	return (s1);
}*/
