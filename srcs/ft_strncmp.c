/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulopez <aulopez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 11:44:16 by aulopez           #+#    #+#             */
/*   Updated: 2019/07/06 10:29:19 by aulopez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdint.h>

/*
** Basic implementation
*/

/*
**int	ft_strncmp(const char *s1, const char *s2, size_t n)
**{
**	if (!n++)
**		return (0);
**	while (--n && *s1 == *s2 && *s1 && *s2)
**	{
**		++s1;
**		++s2;
**	}
**	if (!n && (*--s1 == *--s2))
**		return (0);
**	return (*(unsigned char *)s1 - *(unsigned char *)s2);
**}
*/

static inline int	align_address(const unsigned char **c1,
						const unsigned char **c2, size_t *restrict n)
{
	while ((uintptr_t)*c1 & 0x7)
	{
		if (**c1 != **c2 || !**c1)
			return (1);
		if (!*n)
			return (0);
		++*c1;
		++*c2;
		--*n;
	}
	return (0);
}
static inline void	loopword(const unsigned char **c1,
						const unsigned char **c2, size_t *restrict n)
{
	const uint64_t	*ll1;
	const uint64_t	*ll2;
	uint64_t		one_each_byte;

	one_each_byte = 0x0101010101010101L;
	ll1 = (const uint64_t *)*c1;
	ll2 = (const uint64_t *)*c2;
	while (1)
	{
		if ((*ll1 != *ll2)
				|| (((*ll1 - one_each_byte) & ~*ll1) & (one_each_byte << 7))
				|| !*n)
			break ;
		++ll1;
		++ll2;
		*n -= 8;
	}
	*c1 = (const unsigned char *)ll1;
	*c2 = (const unsigned char *)ll2;
}

int					ft_strncmp(const char *s1, const char *s2, size_t n)
{
	const unsigned char	*cs1;
	const unsigned char	*cs2;

	cs1 = (const unsigned char *)s1;
	cs2 = (const unsigned char *)s2;
	if (n >= 8 && (((uintptr_t)s1 & 0x7) == ((uintptr_t)s2 & 0x7)))
	{
		if (align_address(&cs1, &cs2, &n))
			return (*cs1 - *cs2);
		loopword(&cs1, &cs2, &n);
	}
	if (!n)
		return (0);
	while (*cs1 == *cs2)
	{
		if (!n--)
			return (0);
		else if (!*cs1)
			break ;
		++cs1;
		++cs2;
	}
	return (*cs1 - *cs2);
}
