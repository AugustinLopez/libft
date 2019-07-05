/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulopez <aulopez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 10:29:03 by aulopez           #+#    #+#             */
/*   Updated: 2019/07/05 20:26:31 by aulopez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/*char	*ft_strdup(const char *s1)
{
	char	*buf;
	size_t	i;

	i = 0;
	while (s1[i])
		i++;
	if (!(buf = (char*)malloc(sizeof(*buf) * (i + 1))))
		return (0);
	i = 0;
	while (*s1)
		buf[i++] = *(s1++);
	buf[i] = '\0';
	return (buf);
}*/

char	*ft_strdup(const char *s1)
{
	char	*buf;
	size_t	i;

	i = ft_strlen(s1);
	if (!(buf = (char *)malloc(sizeof(char) * (i + 1))))
		return (0);
	ft_memcpy(buf, s1, i);
	buf[i] = 0;
	return (buf);
}
