/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulopez <aulopez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 15:08:47 by aulopez           #+#    #+#             */
/*   Updated: 2019/07/03 23:37:35 by aulopez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <string.h>

static inline const unsigned char	*longword(const unsigned char *restrict pc,
										const unsigned char c,
										size_t *restrict n)
{
	const uint64_t	*pll;
	uint64_t		one_each_byte;
	uint64_t		c_each_byte;
	uint64_t		loopword;

	pll = (const uint64_t *)pc;
	one_each_byte = 0x0101010101010101L;
	c_each_byte = c | (c << 8);
	c_each_byte |= c_each_byte << 16;
	c_each_byte |= c_each_byte << 32;
	while (*n >= 8)
	{
		loopword = *pll ^ c_each_byte;
		if (((loopword - one_each_byte) & ~loopword) & (one_each_byte << 7))
			break ;
		pll++;
		*n -= 8;
	}
	return ((const unsigned char *)pll);
}

void						*ft_memchr(const void *restrict s, int c, size_t n)
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
		pc = longword(pc, (const unsigned char)c, &n);
	while (n--)
	{
		if (*pc == (unsigned char)c)
			return ((void *)pc);
		++pc;
	}
	return (NULL);
}
