/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnchri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulopez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 13:25:50 by aulopez           #+#    #+#             */
/*   Updated: 2018/12/14 15:37:17 by aulopez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t	ft_strnchri(const char *s, int c, size_t n)
{
	size_t	size;

	size = 2;
	if (*s == c)
		return (1);
	while (*(s++) && n--)
	{
		if (*s == c)
			return (size);
		size++;
	}
	return (0);
}
