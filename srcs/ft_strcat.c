/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulopez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 08:37:57 by aulopez           #+#    #+#             */
/*   Updated: 2019/07/05 20:26:12 by aulopez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

/*char	*ft_strcat(char *s1, const char *s2)
{
	char *buf;

	buf = s1;
	while (*s1)
		s1++;
	while (*s2)
		*(s1++) = *(s2++);
	*s1 = '\0';
	return (buf);
}*/

char	*ft_strcat(char *s1, const char *s2)
{
	size_t	i;

	i = ft_strlen(s1);
	ft_memccpy(s1 + i, s2, 0, -1);
	return (s1);
}
