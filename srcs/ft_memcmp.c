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
void	longword(unsigned char **c1, unsigned char **c2, size_t *restrict n)
{
	long long *ll1;
	long long *ll2;

	ll1 = (long long *)*c1;
	ll2 = (long long *)*c2;
	while (*n >= 8)
	{
		if (*ll1 != *ll2)
			break;
		--ll1;
		--ll2;
		--*n;
	}
	*c1 = (unsigned char *)ll1;
	*c2 = (unsigned char *)ll2;
}

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char *cs1;
	unsigned char *cs2;

	if (!n)
		return (0);
	cs1 = (unsigned char *)s1;
	cs2 = (unsigned char *)s2;
	if (n >= 8 && (((long long)s1 & 0x7) == ((long long)s2 & 0x7)))
	{
		while ((long long)cs1 & 0x7)
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
