/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulopez <aulopez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 15:00:28 by aulopez           #+#    #+#             */
/*   Updated: 2019/07/05 20:26:52 by aulopez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*char	*ft_strcpy(char *dst, const char *src)
{
	char *buf;

	buf = dst;
	while (*src)
		*(dst++) = *(src++);
	*dst = '\0';
	return (buf);
}*/

char	*ft_strcpy(char *dst, const char *src)
{
	ft_memccpy(dst, src, 0, -1);
	return (dst);
}
