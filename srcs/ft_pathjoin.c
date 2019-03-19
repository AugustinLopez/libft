/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pathjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulopez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 09:24:15 by aulopez           #+#    #+#             */
/*   Updated: 2018/11/20 12:10:44 by aulopez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	null_prot_strlen(char const *s)
{
	size_t	i;

	i = 0;
	if (s)
		while (*s++)
			i++;
	return (i);
}

char			*ft_pathjoin(char const *s1, char const *s2)
{
	char	*p;
	char	*cbuf;
	size_t	len1;
	size_t	len2;
	size_t	tmp;

	len1 = null_prot_strlen(s1);
	len2 = null_prot_strlen(s2);
	if (!(p = ft_strnew(len1 + len2 + 1)))
		return (0);
	cbuf = p;
	tmp = len1;
	while (len1--)
		*(p++) = *(s1++);
	if (((tmp && *(p - 1) != '/') || !tmp) && (!s2 || *s2 != '/'))
		*(p++) = '/';
	while (len2--)
		*(p++) = *(s2++);
	*p = 0;
	return (cbuf);
}
