/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulopez <aulopez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 14:56:45 by aulopez           #+#    #+#             */
/*   Updated: 2019/07/04 23:55:28 by aulopez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <string.h>

static inline uint64_t	set_mask(unsigned char c)
{
	uint64_t	mask;

	mask = c & 0xff;
	mask = (mask << 8) | mask;
	mask = (mask << 16) | mask;
	mask = (mask << 32) | mask;
	return (mask);
}

void					*ft_memset(void *s, int c, size_t n)
{
	uint64_t		mask;
	uint64_t		*pu64;
	unsigned char	*pc;

	pc = (unsigned char *)s;
	if (n >= 8)
	{
		while (((uintptr_t)pc & 0x7))
		{
			*pc++ = (unsigned char)c;
			--n;
		}
		mask = set_mask((unsigned char)c);
		pu64 = (uint64_t *)pc;
		while (n >= 8)
		{
			*pu64++ = mask;
			n -= 8;
		}
		pc = (unsigned char *)pu64;
	}
	while (n--)
		*pc++ = (unsigned char)c;
	return (s);
}
