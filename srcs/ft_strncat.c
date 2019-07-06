/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulopez <aulopez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 15:13:54 by aulopez           #+#    #+#             */
/*   Updated: 2019/07/06 09:57:01 by aulopez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

/*char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char *buf;

	if (!n && !s2 && s1)
		return (s1);
	buf = s1;
	while (*s1)
		s1++;
	while (*s2 && n--)
		*(s1++) = *(s2++);
	*s1 = '\0';
	return (buf);
}
*/

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	ft_memccpy(s1 + ft_strlen(s1), s2, 0, n);
	return (s1);
}
