/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulopez <aulopez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 01:22:00 by aulopez           #+#    #+#             */
/*   Updated: 2019/07/06 10:36:21 by aulopez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strstr(const char *haystack, const char *needle)
{
	const char	*hs;
	const char	*ne;

	if (!*needle)
		return ((char *)haystack);
	if (!(haystack = ft_strchr(haystack, *needle)))
		return ((char *)haystack);
	while (*haystack)
	{
		if (*haystack == *needle && *haystack)
		{
			hs = haystack;
			ne = needle;
			while (*(ne++) == *(hs++))
				if (!*ne)
					return ((char *)haystack);
		}
		++haystack;
	}
	return (NULL);
}
