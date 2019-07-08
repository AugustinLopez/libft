/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulopez <aulopez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 01:22:00 by aulopez           #+#    #+#             */
/*   Updated: 2019/07/08 11:21:00 by aulopez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>

/*
** Basic implementation
*/

char	*ft_strrchr(const char *s, int c)
{
	char	*pc;

	pc = 0;
	if (*s == c)
		pc = (char*)s;
	while (*(s++))
		if (*s == c)
			pc = (char*)s;
	return (pc);
}

/*
**static inline char	*basic_strrchr(const char *restrict s,
**						char *restrict pc, int c)
**{
**	if (*s == c)
**		pc = (char *)s;
**	while (*(s++))
**		if (*s == c)
**			pc = (char *)s;
**	return (pc);
**}
**
**static inline char *loopword(const char *restrict s, char *restrict pc,
**						char c)
**{
**	const uint64_t *pll;
**	uint64_t		one_each_byte;
**	uint64_t		c_each_byte;
**	uint64_t		zero_mask;
**
**	pll = (const uint64_t *)s;
**	one_each_byte = 0x0101010101010101L;
**	c_each_byte = c | (c << 8);
**	c_each_byte |= c_each_byte << 16;
**	c_each_byte |= c_each_byte << 32;
**	while (1)
**	{
**		zero_mask = *pll ^ c_each_byte;
**		if (((*pll - one_each_byte) & ~*pll) & (one_each_byte << 7))
**			break ;
**		if (((zero_mask - one_each_byte) & ~zero_mask) & (one_each_byte << 7))
**			pc = (char *)pll;
**		pll++;
**	}
**	if (!c)
**		pc = (char *)pll;
**	return (basic_strrchr(s, pc, c));
**}
**
**char	*ft_strrchr(const char *s, int c)
**{
**	char	*pc;
**
**	pc = NULL;
**	if (*s == (char)c)
**		pc = (char *)s;
**	while ((uintptr_t)s & 0x7)
**	{
**		if (*s == (char)c)
**			pc = (char *)s;
**		if (!*s++)
**			return (pc);
**	}
**	return(loopword(s, pc, (char)c));
**}
*/
