/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulopez <aulopez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 10:01:38 by aulopez           #+#    #+#             */
/*   Updated: 2019/07/01 18:26:36 by aulopez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	void				*ptr;

	if ((ptr = ft_memchr(src, c, n)))
	{
		n = (unsigned long long)ptr - (unsigned long long)src + 1;
		return (ft_memcpy(dst, src, n) + n);
	}
	ft_memcpy(dst, src, n);
	return (NULL);
}
