/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulopez <aulopez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 10:01:38 by aulopez           #+#    #+#             */
/*   Updated: 2019/07/02 12:34:04 by aulopez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

static inline int	align_address(unsigned char **cdst, unsigned char **csrc,
						unsigned char c, size_t *n)
{
	while ((long long)cdst & 0x7)
	{
		if ((*(*cdst++) = *(*csrc++)) == c)
			return (1);
		--(*n);
	}
	return (0);
}

static inline void	longword(unsigned char **cdst, unsigned char **csrc,
								unsigned char c, size_t *restrict n)
{
	long long	*lldst;
	long long	*llsrc;
	long long	one_each_byte;
	long long	c_each_byte;
	long long	loopword;

	lldst = (long long *)*cdst;
	llsrc = (long long *)*csrc;
	one_each_byte = 0x0101010101010101;
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

void				*ft_memccpy(void *restrict s1, const void *restrict s2,
						int c, size_t n)
{
	unsigned char	*cdst;
	unsigned char	*csrc;

	if (!s1 && !s2)
		return (s1);
	cdst = (unsigned char *)s1;
	csrc = (unsigned char *)s2;
	if ((n >= 8) && (((long long)s1 & 0x7) == ((long long)s2 & 0x7)))
	{
		if (align_address(&cdst, &csrc, (unsigned char)c, &n))
			return (cdst);
		longword(&cdst, &csrc, (unsigned char)c, &n);
	}
	while (n--)
		if ((*cdst++ = *csrc++) == (unsigned char)c)
			return (cdst);
	return (NULL);
}
