/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulopez <aulopez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 16:04:50 by aulopez           #+#    #+#             */
/*   Updated: 2019/07/02 14:39:27 by aulopez          ###   ########.fr       */
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

void				*ft_memcpy(void *restrict dst, const void *restrict src,
						size_t n)
{
	char		*cdst;
	char		*csrc;
	long long	*lldst;
	long long	*llsrc;

	if (!dst && !src)
		return (dst);
	cdst = (char *)dst;
	csrc = (char *)src;
	if ((n >= 8) && (((long long)dst & 0x7) == ((long long)src & 0x7)))
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
	return (dst);
}
