/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulopez <aulopez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 15:08:47 by aulopez           #+#    #+#             */
/*   Updated: 2019/08/06 12:23:51 by aulopez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>
#include <string.h>

/*
**void	*ft_memchr(const void *s, int c, size_t n)
**{
**	const unsigned char	*pc;
**
**	pc = (const unsigned char *)s;
**	while (n--)
**	{
**if (*pc == (unsigned char)c)
**			return ((void *)pc);
**		++pc;
**	}
**	return (NULL);
**}
*/

static inline const unsigned char	*loopword(const unsigned char *pc,
										const unsigned char c,
										size_t *n)
{
	const uint64_t	*pll;
	uint64_t		c_each_byte;
	uint64_t		zero_mask;

	pll = (const uint64_t *)pc;
	c_each_byte = c | (c << 8);
	c_each_byte |= c_each_byte << 16;
	c_each_byte |= c_each_byte << 32;
	while (*n >= 8)
	{
		zero_mask = *pll ^ c_each_byte;
		if (((zero_mask - ONE_EACH_BYTE) & ~zero_mask) & REV_EACH_BYTE)
			break ;
		++pll;
		*n -= 8;
	}
	return ((const unsigned char *)pll);
}

void								*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*pc;

	pc = (const unsigned char *)s;
	while ((uintptr_t)pc & 0x7)
	{
		if (*pc == (unsigned char)c)
			return ((void *)pc);
		++pc;
		if (!--n)
			return (NULL);
	}
	if (n >= 8)
		pc = loopword(pc, (const unsigned char)c, &n);
	while (n--)
	{
		if (*pc == (unsigned char)c)
			return ((void *)pc);
		++pc;
	}
	return (NULL);
}
