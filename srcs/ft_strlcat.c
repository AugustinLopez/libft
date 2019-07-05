/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulopez <aulopez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 16:10:13 by aulopez           #+#    #+#             */
/*   Updated: 2019/07/05 20:45:30 by aulopez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t	ft_strlcat(char *s1, const char *s2, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	k;

	j = ft_strlen(s2);
	if (!s1 && !size)
		return (j);
	i = ft_strlen(s1);
	if (i > size)
		return (size + j);
	if (!size || !j)
		return (i + j);
	if (size > i)
	{
		k = j < size - i - 1 ? j : size - i - 1;
		ft_memccpy(s1 + i, s2, 0, k);
		if (k == j)
			s1[i + k] = 0;
	}
	return (i + j);
}
/*
size_t	ft_strlcat(char *s1, const char *s2, size_t size)
{
	size_t i;
	size_t j;
	size_t k;

	i = 0;
	j = 0;
	k = 0;
	while (s2[j])
		j++;
	if (!s1 && !size)
		return (j);
	while (s1[i])
		i++;
	if (i > size)
		return (size + j);
	if (!size || !j)
		return (i + j);
	while (k < j && k + i + 1 < size)
	{
		s1[i + k] = s2[k];
		k++;
	}
	if (k <= j)
		s1[i + k] = '\0';
	return (i + j);
}*/
