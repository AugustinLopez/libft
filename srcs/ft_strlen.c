/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulopez <aulopez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 10:29:13 by aulopez           #+#    #+#             */
/*   Updated: 2019/07/08 11:21:52 by aulopez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdint.h>

/*
** Basic implementation
*/

/*
**size_t	ft_strlen(const char *s)
**{
**	size_t	i;
**
**	i = 0;
**	while (*(s++))
**		i++;
**	return (i);
**}
*/

static inline size_t	loopword(const char *restrict s, size_t n)
{
	const uint64_t	*pll;
	uint64_t		one_each_byte;
	size_t			len;

	len = n;
	pll = (const uint64_t *)s;
	one_each_byte = 0x0101010101010101L;
	while (1)
	{
		if (((*pll - one_each_byte) & ~*pll) & (one_each_byte << 7))
			break ;
		++pll;
		len += 8;
	}
	s = (const char *)pll;
	while (1)
	{
		if (!*s++)
			return (len);
		++len;
	}
	return (0);
}

size_t					ft_strlen(const char *s)
{
	size_t	n;

	n = 0;
	while ((uintptr_t)s & 0x7)
	{
		if (!*s++)
			return (n);
		++n;
	}
	return (loopword(s, n));
}
