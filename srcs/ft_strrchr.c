/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulopez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 01:22:00 by aulopez           #+#    #+#             */
/*   Updated: 2019/07/05 22:51:11 by aulopez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*char	*ft_strrchr(const char *s, int c)
{
	char	*buf;

	buf = 0;
	if (*s == c)
		buf = (char*)s;
	while (*(s++))
		if (*s == c)
			buf = (char*)s;
	return (buf);
}*/

#include "libft.h"
#include <stdint.h>


static inline char *longword(char *restrict s, char c)
{
	const uint64_t *pll;
	uint64_t		one_each_byte;
	uint64_t		c_each_byte;
	uint64_t		loopword;
	const char		*pc;

	pll = (const uint64_t *)s;
	one_each_byte = 0x0101010101010101L;
	c_each_byte = c | (c << 8);
	c_each_byte |= c_each_byte << 16;
	c_each_byte |= c_each_byte << 32;
	pc = NULL;
	while (1)
	{
		loopword = *pll ^ c_each_byte;
		if (((*pll - one_each_byte) & ~*pll) & (one_each_byte << 7))
			break ;
		if (((loopword - one_each_byte) & ~loopword) & (one_each_byte << 7))
			pc = (char *)pll;
		pll++;
	}
	if (!c)
		pc = (char *)pll;
	return ((char *)pc);
}

static inline char	*basic_strrchr(char *s, int c)
{
	char	*buf;

	buf = NULL;
	if (*s == c)
		buf = s;
	while (*(s++))
		if (*s == c)
			buf = s;
	return (buf);
}


char	*ft_strrchr(const char *s, int c)
{
	char	*pc;

	pc = NULL;
	if (*s == (char)c)
		pc = (char *)s;
	while ((uintptr_t)s & 0x7)
	{
		if (*s == (char)c)
			pc = (char *)s;
		if (!*s++)
			return (pc);
	}
	if (!(s = (const char *)longword((char *)s, (char)c)))
		return (pc);
	pc = (char *)s;
	return (basic_strrchr(pc, c));
}
