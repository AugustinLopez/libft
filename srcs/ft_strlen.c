/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulopez <aulopez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 10:29:13 by aulopez           #+#    #+#             */
/*   Updated: 2019/07/05 19:20:40 by aulopez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdint.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*(s++))
		i++;
	return (i);
}

/*
static inline size_t	longword(const char *restrict s, size_t n)
{
	const uint64_t	*pu64;
	uint64_t		one_each_byte;
	uint64_t		loopword;
	size_t			len;

	len = n;
	pu64 = (const uint64_t *)s;
	one_each_byte = 0x0101010101010101L;
	while (1)
	{
		if (((*pu64 - one_each_byte) & ~*pu64) & (one_each_byte << 7))
			break ;
		++pu64;
		*n += 8;
	}
	s = (const char *)pu64;
	while (1)
	{
		if (!*s++)
			return (n);
		++n;
	}
	return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t		n;

	n = 0;
	while ((uintptr_t)s & 0x7)
	{
		if (!*s++)
			return (n);
		++n;
	}
	return (longword(s, n));
}
*/
