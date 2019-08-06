/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulopez <aulopez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 16:04:50 by aulopez           #+#    #+#             */
/*   Updated: 2019/08/06 12:21:30 by aulopez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <string.h>

/*
** Basic implementation
*/

/*
**int	ft_memcmp(const void *s1, const void *s2, size_t n)
**{
**	unsigned char	*cs1;
**	unsigned char	*cs2;
**
**	if (!n)
**		return (0);
**	cs1 = (unsigned char*)s1;
**	cs2 = (unsigned char*)s2;
**	if (*cs1 == *cs2)
**	{
**		while (--n && *cs1 == *cs2)
**		{
**			++cs1;
**			++cs2;
**		}
**	}
**	return (*cs1 - *cs2);
**}
*/

static inline int	loopword(const unsigned char **cs1,
						const unsigned char **cs2, size_t *n)
{
	const uint64_t *lls1;
	const uint64_t *lls2;

	while ((uintptr_t)*cs1 & 0x7)
	{
		if (**cs1 != **cs2)
			return (1);
		++*cs1;
		++*cs2;
		--*n;
	}
	lls1 = (const uint64_t *)*cs1;
	lls2 = (const uint64_t *)*cs2;
	while (*n >= 8)
	{
		if (*lls1 != *lls2)
			break ;
		++lls1;
		++lls2;
		*n -= 8;
	}
	*cs1 = (const unsigned char *)lls1;
	*cs2 = (const unsigned char *)lls2;
	return (0);
}

int					ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char *cs1;
	const unsigned char *cs2;

	cs1 = (const unsigned char *)s1;
	cs2 = (const unsigned char *)s2;
	if (n >= 8 && (((uintptr_t)s1 & 0x7) == ((uintptr_t)s2 & 0x7)))
	{
		if (loopword(&cs1, &cs2, &n))
			return (*cs1 - *cs2);
	}
	if (!n)
		return (0);
	while (*cs1 == *cs2)
	{
		if (!--n)
			break ;
		++cs1;
		++cs2;
	}
	return (*cs1 - *cs2);
}
