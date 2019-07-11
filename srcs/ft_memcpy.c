/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulopez <aulopez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 16:04:50 by aulopez           #+#    #+#             */
/*   Updated: 2019/07/08 11:22:51 by aulopez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <string.h>

/*
** Basic implementation
*/

/*
**void	*ft_memcpy(void *restrict s1, const void *restrict s2, size_t n)
**{
**	unsigned char	*cs1;
**	unsigned char	*cs2;
**
**	cs1 = (unsigned char *)s1;
**	cs2 = (unsigned char *)s2;
**	while (n--)
**		*cs1++ = *cs2++;
**	return (s1);
**}
*/

static inline void	loopword(unsigned char **restrict cs1,
						unsigned char **restrict cs2,
						size_t *restrict n)
{
	uint64_t	*lls1;
	uint64_t	*lls2;

	while ((uintptr_t)*cs1 & 0x7)
	{
		*((*cs1)++) = *((*cs2)++);
		--(*n);
	}
	lls1 = (uint64_t *)*cs1;
	lls2 = (uint64_t *)*cs2;
	while (*n >= 8)
	{
		*lls1++ = *lls2++;
		*n -= 8;
	}
	*cs1 = (unsigned char *)lls1;
	*cs2 = (unsigned char *)lls2;
}

void				*ft_memcpy(void *restrict s1, const void *restrict s2,
						size_t n)
{
	unsigned char	*cs1;
	unsigned char	*cs2;

	cs1 = (unsigned char *)s1;
	cs2 = (unsigned char *)s2;
	if ((n >= 8) && (((uintptr_t)s1 & 0x7) == ((uintptr_t)s2 & 0x7)))
		loopword(&cs1, &cs2, &n);
	while (n--)
		*cs1++ = *cs2++;
	return (s1);
}
