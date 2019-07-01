/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulopez <aulopez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 15:08:47 by aulopez           #+#    #+#             */
/*   Updated: 2019/07/01 15:29:02 by aulopez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

static inline char	*longword(char *pc, unsigned char c, size_t *n)
{
	long long		one_each_byte;
	long long		c_each_byte;
	long long		loopword;

	pll = (const long long *)pc;
	one_each_byte = 0x0101010101010101;
	c_each_byte = c | ( c << 8);
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
	return ((char *)pll);
}

void				*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	chr;
	const char		*pc;

	chr = (unsigned char)c;
	pc = (char *)s;
	if (n >= 8)
	{
		while ((long long)pc & 0x7)
		{
			if (*pc++ == chr)
				return (--pc);
			--n;
		}
		pc = longword(pc, chr, &n);
	}
	while (n--)
		if (*pc++ == chr)
			return (--pc);
	return (NULL);
}
