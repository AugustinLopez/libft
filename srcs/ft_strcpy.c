/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulopez <aulopez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 15:00:28 by aulopez           #+#    #+#             */
/*   Updated: 2019/07/09 10:39:14 by aulopez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdint.h>

/*
** Basic implementation
*/

/*
**char	*ft_strcpy(char *restrict s1, const char *restrict s2)
**{
**	ft_memccpy(s1, s2, 0, -1);
**	return (s1);
**}
*/

static inline int	align_address(char **restrict cs1,
						const char **restrict cs2)
{
	while ((uintptr_t)*cs1 & 0x7)
	{
		if (!(**cs1 = **cs2))
			return (1);
		++(*cs1);
		++(*cs2);
	}
	return (0);
}

static inline void	loopword(char **restrict cs1, const char **restrict cs2)
{
	uint64_t	*ll1;
	uint64_t	*ll2;
	uint64_t	one_each_byte;
	uint64_t	catching_mask;

	ll1 = (uint64_t *)*cs1;
	ll2 = (uint64_t *)*cs2;
	one_each_byte = 0x0101010101010101L;
	catching_mask = one_each_byte << 7;
	while (1)
	{
		if (((*ll2 - one_each_byte) & ~*ll2) & catching_mask)
			break ;
		*ll1++ = *ll2++;
	}
	*cs1 = (char *)ll1;
	*cs2 = (char *)ll2;
}

char				*ft_strcpy(char *restrict s1, const char *restrict s2)
{
	char		*cs1;
	const char	*cs2;

	cs1 = s1;
	cs2 = s2;
	if ((((uintptr_t)s1 & 0x7) == ((uintptr_t)s2 & 0x7)))
	{
		if (align_address(&cs1, &cs2))
			return (s1);
		loopword(&cs1, &cs2);
	}
	while (1)
	{
		if (!(*cs1 = *cs2))
			return (s1);
		++cs1;
		++cs2;
	}
	return (s1);
}
