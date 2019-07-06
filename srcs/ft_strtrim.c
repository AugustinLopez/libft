/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulopez <aulopez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 09:25:26 by aulopez           #+#    #+#             */
/*   Updated: 2019/07/06 11:20:18 by aulopez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

static inline size_t	trim_end(const char *s)
{
	size_t	n;
	size_t	trim;

	n = 0;
	trim = 0;
	while (*s)
	{
		if (*s == ' ' || (*s >= 9 && *s <= 13))
			++trim;
		else
			trim = 0;
		++s;
		++n;
	}
	return (n - trim);
}

char					*ft_strtrim(char const *s)
{
	while (*s == ' ' || (*s >= 9 && *s <= 13))
		s++;
	return (ft_strsub(s, 0, trim_end(s)));
}
