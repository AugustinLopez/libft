/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulopez <aulopez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 10:07:22 by aulopez           #+#    #+#             */
/*   Updated: 2019/07/09 10:39:48 by aulopez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "libft.h"

/*
** Basic implementation
*/

/*
**int	ft_strcmp(const char *s1, const char *s2)
**{
**	while (*s1 == *s2 && *s1 && *s2)
**	{
**		++s1;
**		++s2;
**	}
**	return (*(unsigned char*)s1 - *(unsigned char*)s2);
**}
*/

static inline int	align_loop(const unsigned char **c1,
						const unsigned char **c2)
{
	while ((uintptr_t)*c1 & 0x7)
	{
		if (**c1 != **c2 || !**c1)
			return (1);
		++*c1;
		++*c2;
	}
	return (0);
}
static inline int	loopword(const unsigned char **c1,
						const unsigned char **c2)
{
	const uint64_t	*ll1;
	const uint64_t	*ll2;
	uint64_t		one_each_byte;
	uint64_t		catching_mask;

	if (align_loop(c1, c2))
		return (1);
	one_each_byte = 0x0101010101010101L;
	catching_mask = one_each_byte << 7;
	ll1 = (const uint64_t *)*c1;
	ll2 = (const uint64_t *)*c2;
	while (1)
	{
		if ((*ll1 != *ll2)
			|| (((*ll1 - one_each_byte) & ~*ll1) & catching_mask))
			break ;
		++ll1;
		++ll2;
	}
	*c1 = (const unsigned char *)ll1;
	*c2 = (const unsigned char *)ll2;
	return (0);
}

int					ft_strcmp(const char *s1, const char *s2)
{
	const unsigned char	*cs1;
	const unsigned char	*cs2;

	cs1 = (const unsigned char *)s1;
	cs2 = (const unsigned char *)s2;
	if ((((uintptr_t)s1 & 0x7) == ((uintptr_t)s2 & 0x7)))
	{
		if (loopword(&cs1, &cs2))
			return (*cs1 - *cs2);
	}
	while (*cs1 == *cs2)
	{
		if (!*cs1)
			break ;
		++cs1;
		++cs2;
	}
	return (*cs1 - *cs2);
}
