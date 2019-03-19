/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strastri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulopez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 01:22:00 by aulopez           #+#    #+#             */
/*   Updated: 2019/01/10 14:47:45 by aulopez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strastri(const char *s1, const char *s2)
{
	size_t	n;
	size_t	m;

	n = 0;
	if (!s1 || !s2)
		return (0);
	while (*s2 && !n)
	{
		n = ft_strchri(s1, *s2);
		s2++;
	}
	while (*s2)
	{
		m = ft_strnchri(s1, *s2, n);
		s2++;
		if (m != 0 && m < n)
			n = m;
		if (n == 1)
			break ;
	}
	if (n == 0)
		return (0);
	return (n);
}
