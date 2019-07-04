/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulopez <aulopez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 11:33:47 by aulopez           #+#    #+#             */
/*   Updated: 2019/07/04 16:30:16 by aulopez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

static inline void	longword(char **cdst, char **csrc, size_t *n)
{
	long long	*lldst;
	long long	*llsrc;

	while (((long long)*cdst & 0x7))
	{
		*((*cdst)--) = *((*csrc)--);
		--(*n);
	}
	**cdst = **csrc;
	lldst = (long long *)*cdst - 1;
	llsrc = (long long *)*csrc - 1;
	while (*n >= 8)
	{
		*lldst-- = *llsrc--;
		*n -= 8;
	}
	if (*n)
	{
		*cdst = (char *)lldst - 1;
		*csrc = (char *)llsrc - 1;
	}
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*cdst;
	char		*csrc;

	if (dst <= src)
		return (ft_memcpy(dst, src, len));
	if (!len || (!dst && !src))
		return (dst);
	cdst = (char *)dst + len - 1;
	csrc = (char *)src + len - 1;
	if ((len >= 15) && (((long long)dst & 0x7) == ((long long)src & 0x7)))
		longword(&cdst, &csrc, &len);
	while (len--)
		*cdst-- = *csrc--;
	return (dst);
}
