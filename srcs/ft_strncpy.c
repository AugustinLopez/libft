/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulopez <aulopez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 15:02:50 by aulopez           #+#    #+#             */
/*   Updated: 2019/07/05 20:03:52 by aulopez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

/*char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	ft_memccpy(dst, src, 0, len);
	return (dst);
}*/


char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char *buf;

	if (!len)
		return (dst);
	buf = dst;
	len++;
	while (*src && --len)
		*(dst++) = *(src++);
	if (len--)
		while (len--)
			if (*dst)
				*(dst++) = '\0';
	return (buf);
}
