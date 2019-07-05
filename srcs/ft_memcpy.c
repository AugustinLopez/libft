/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulopez <aulopez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 16:04:50 by aulopez           #+#    #+#             */
/*   Updated: 2019/07/03 09:10:46 by aulopez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <string.h>

static inline void	longword(unsigned char **restrict cs1,
						unsigned char **restrict cs2,
						size_t *restrict n)
{
	uint64_t	*ulls1;
	uint64_t	*ulls2;

	while ((uintptr_t)*cs1 & 0x7)
	{
		*((*cs1)++) = *((*cs2)++);
		--(*n);
	}
		ulls1 = (uint64_t *)*cs1;
		ulls2 = (uint64_t *)*cs2;
		while (*n >= 8)
		{
			*ulls1++ = *ulls2++;
			*n -= 8;
		}
		*cs1 = (unsigned char *)ulls1;
		*cs2 = (unsigned char *)ulls2;
}

void				*ft_memcpy(void *restrict s1, const void *restrict s2,
						size_t n)
{
	unsigned char	*cs1;
	unsigned char	*cs2;

	if (!s1 && !s2)
		return (s1);
	cs1 = (unsigned char *)s1;
	cs2 = (unsigned char *)s2;
	if ((n >= 8) && (((uintptr_t)s1 & 0x7) == ((uintptr_t)s2 & 0x7)))
		longword(&cs1, &cs2, &n);
	while (n--)
		*cs1++ = *cs2++;
	return (s1);
}
