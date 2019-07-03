/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulopez <aulopez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 14:56:45 by aulopez           #+#    #+#             */
/*   Updated: 2019/07/03 09:06:22 by aulopez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

static inline long long	set_mask(char c)
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
	long long	mask;
	long long	*pll;
	char		*pc;

	pc = (char *)s;
	if (n >= 8)
	{
		while (((long long)pc & 0x7))
		{
			*pc++ = (char)c;
			--n;
		}
		mask = set_mask((char)c);
		pll = (long long *)pc;
		while (n >= 8)
		{
			*pll++ = mask;
			n -= 8;
		}
		pc = (char *)pll;
	}
	while (n--)
		*pc++ = (char)c;
	return (s);
}
