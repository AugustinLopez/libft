/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulopez <aulopez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 01:22:00 by aulopez           #+#    #+#             */
/*   Updated: 2019/07/06 10:41:23 by aulopez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	const char	*hs;
	const char	*ne;
	size_t		i;

	if (!*needle)
		return ((char*)haystack);
	if (!len++ && !haystack)
		return (NULL);
	while (*haystack && --len)
	{
		i = len + 1;
		if (*haystack == *needle && *haystack)
		{
			hs = haystack;
			ne = needle;
			while (*(ne++) == *(hs++) && --i)
				if (!*ne)
					return ((char*)haystack);
		}
		++haystack;
	}
	return (NULL);
}
