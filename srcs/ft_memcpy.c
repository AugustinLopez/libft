/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulopez <aulopez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 16:04:50 by aulopez           #+#    #+#             */
/*   Updated: 2019/07/02 12:33:22 by aulopez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

static inline void	align_address(char **cdst, char **csrc, size_t *n)
{
	while ((long long)cdst & 0x7)
	{
		*((*cdst)++) = *((*csrc)++);
		--(*n);
	}
}

void				*ft_memcpy(void *restrict s1, const void *restrict s2,
						size_t n)
{
	char		*cdst;
	char		*csrc;
	long long	*lldst;
	long long	*llsrc;

	if (!s1 && !s2)
		return (s1);
	cdst = (char *)s1;
	csrc = (char *)s2;
	if ((n >= 8) && (((long long)s1 & 0x7) == ((long long)s2 & 0x7)))
	{
		align_address(&cdst, &csrc, &n);
		lldst = (long long *)cdst;
		llsrc = (long long *)csrc;
		while (n >= 8)
		{
			*lldst++ = *llsrc++;
			n -= 8;
		}
		cdst = (char *)lldst;
		csrc = (char *)llsrc;
	}
	while (n--)
		*cdst++ = *csrc++;
	return (s1);
}
