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

#include <string.h>

static inline long long	set_mask(unsigned char c)
{
	long long	mask;

	mask = c & 0xff;
	mask = (mask << 8) | mask;
	mask = (mask << 16) | mask;
	mask = (mask << 32) | mask;
	return (mask);
}

void					*ft_memset(void *s, int c, size_t n)
{
	long long		mask;
	long long		*pll;
	unsigned char	*pc;

	pc = (unsigned char *)s;
	if (n >= 8)
	{
		while (((long long)pc & 0x7))
		{
			*pc++ = (unsigned char)c;
			--n;
		}
		mask = set_mask((unsigned char)c);
		pll = (long long *)pc;
		while (n >= 8)
		{
			*pll++ = mask;
			n -= 8;
		}
		pc = (unsigned char *)pll;
	}
	while (n--)
		*pc++ = (unsigned char)c;
	return (s);
}
