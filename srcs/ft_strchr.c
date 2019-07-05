/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulopez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 01:22:00 by aulopez           #+#    #+#             */
/*   Updated: 2019/07/05 22:12:48 by aulopez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*char	*ft_strchr(const char *s, int c)
{
	if (*s == c)
		return ((char*)s);
	while (*(s++))
		if (*s == c)
			return ((char*)s);
	return (0);
}*/

#include "libft.h"
#include <stdint.h>

static inline char	*basic_strchr(char *s, char c)
{
	if (*s == c)
		return (s);
	while (*(++s))
		if (*s == c)
			return (s);
	return (NULL);
}

static inline char *longword(char *restrict s, char c)
{
	const uint64_t *pll;
	uint64_t		one_each_byte;
	uint64_t		c_each_byte;
	uint64_t		loopword;

	pll = (const uint64_t *)s;
	one_each_byte = 0x0101010101010101L;
	c_each_byte = c | (c << 8);
	c_each_byte |= c_each_byte << 16;
	c_each_byte |= c_each_byte << 32;
	while (1)
	{
		loopword = *pll ^ c_each_byte;
		if (((loopword - one_each_byte) & ~loopword) & (one_each_byte << 7))
			break ;
		else if (((*pll - one_each_byte) & ~*pll) & (one_each_byte << 7))
			break ;
		pll++;
	}
	s = (char *)pll;
	return (s);
}

char	*ft_strchr(const char *s, int c)
{
	if (!*s)
		return (NULL);
	while ((uintptr_t)s & 0x7)
	{
		if (*s == (char)c)
			return ((char *)s);
		if (!*++s)
			return (NULL);
	}
	s = (const char *)longword((char *)s, (char)c);
	return (basic_strchr((char *)s, (char)c));
}
