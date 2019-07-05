/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulopez <aulopez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 10:01:38 by aulopez           #+#    #+#             */
/*   Updated: 2019/07/05 16:37:17 by aulopez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

static inline int	align_address(unsigned char **cdst, unsigned char **csrc,
						unsigned char c, size_t *n)
{
	while ((unsigned long long)*cdst & 0x7)
	{
		if ((**cdst = **csrc) == c)
			return (1);
		(*cdst)++;
		(*csrc)++;
		--(*n);
	}
	return (0);
}

static inline void	longword(unsigned char **cdst, unsigned char **csrc,
								unsigned char c, size_t *restrict n)
{
	unsigned long long	*lldst;
	unsigned long long	*llsrc;
	unsigned long long	one_each_byte;
	unsigned long long	c_each_byte;
	unsigned long long	loopword;

	lldst = (unsigned long long *)*cdst;
	llsrc = (unsigned long long *)*csrc;
	one_each_byte = 0x0101010101010101L;
	c_each_byte = c | (c << 8);
	c_each_byte |= c_each_byte << 16;
	c_each_byte |= c_each_byte << 32;
	while (*n >= 8)
	{
		loopword = *llsrc ^ c_each_byte;
		if (((loopword - one_each_byte) & ~loopword) & (one_each_byte << 7))
			break ;
		*lldst++ = *llsrc++;
		*n -= 8;
	}
	*cdst = (unsigned char *)lldst;
	*csrc = (unsigned char *)llsrc;
}

void				*ft_memccpy(void *restrict dst, const void *restrict src,
						int c, size_t n)
{
	unsigned char	*cdst;
	unsigned char	*csrc;

	cdst = (unsigned char *)dst;
	csrc = (unsigned char *)src;
	if ((n >= 8) && (((unsigned long long)dst & 0x7) == ((unsigned long long)src & 0x7)))
	{
		if (align_address(&cdst, &csrc, (unsigned char)c, &n))
			return (cdst + 1);
		longword(&cdst, &csrc, (unsigned char)c, &n);
	}
	while (n--)
	{
		if ((*cdst = *csrc) == (unsigned char)c)
			return (cdst + 1);
		cdst++;
		csrc++;
	}
	return (NULL);
}
