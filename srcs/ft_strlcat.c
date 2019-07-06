/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulopez <aulopez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 16:10:13 by aulopez           #+#    #+#             */
/*   Updated: 2019/07/06 13:41:04 by aulopez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t	ft_strlcat(char *s1, const char *s2, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	k;

	if (!s1 && !size)
		return (ft_strlen(s2));
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	if (i > size)
		return (size + j);
	else if (!size || !j)
		return (i + j);
	else if (size > i)
	{
		k = j < size - i - 1 ? j : size - i - 1;
		ft_memccpy(s1 + i, s2, 0, k);
		s1[i + k] = 0;
	}
	return (i + j);
}
