/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulopez <aulopez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 16:04:50 by aulopez           #+#    #+#             */
/*   Updated: 2019/07/05 15:21:51 by aulopez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <string.h>
/*
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*cs1;
	unsigned char	*cs2;

	if (!n)
		return (0);
	cs1 = (unsigned char*)s1;
	cs2 = (unsigned char*)s2;
	if (*cs1 == *cs2)
		while (--n && *(++cs1) == *(++cs2))
			;
	return (*cs1 - *cs2);
}
*/
void	longword(const unsigned char **c1, const unsigned char **c2,
			size_t *restrict n)
{
	const uint64_t *ll1;
	const uint64_t *ll2;

	ll1 = (const uint64_t *)*c1;
	ll2 = (const uint64_t *)*c2;
	while (*n >= 8)
	{
		if (*ll1 != *ll2)
			break;
		++ll1;
		++ll2;
		--*n;
	}
	*c1 = (const unsigned char *)ll1;
	*c2 = (const unsigned char *)ll2;
}

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char *cs1;
	const unsigned char *cs2;

	if (!n)
		return (0);
	cs1 = (const unsigned char *)s1;
	cs2 = (const unsigned char *)s2;
	if (n >= 8 && (((uintptr_t)s1 & 0x7) == ((uintptr_t)s2 & 0x7)))
	{
		while ((uintptr_t)cs1 & 0x7)
		{
			if (*cs1++ != *cs2++)
				return (*--cs1 - *--cs2);
			--n;
		}
		longword(&cs1, &cs2, &n);
	}
	while (*cs1++ == *cs2++)
		if (!--n)
			break ;
	return (*--cs1 - *--cs2);
}
