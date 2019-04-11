/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strssplit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulopez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 09:25:07 by aulopez           #+#    #+#             */
/*   Updated: 2019/04/10 16:28:39 by aulopez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	null_prot_nbr_word(const char *s, const char *c)
{
	size_t	occurence;

	if (!s)
		return (0);
	while (ft_strchr(c, *s))
		s++;
	if (!*s)
		return (0);
	occurence = 1;
	while (*++s)
	{
		if (!ft_strchr(c, *s) && ft_strchr(c, *(s - 1)))
			occurence++;
	}
	return (occurence);
}

static void		start_and_end(const char *s, const char *c,
								size_t *start, size_t *end)
{
	*start = *end;
	while (s[*start])
	{
		if (ft_strchr(c, s[*start]))
			*start += 1;
		else
		{
			*end = *start;
			while (s[*end] && !(ft_strchr(c, s[*end])))
				*end += 1;
			return ;
		}
	}
}

static char		*ft_strunchr(const char *s, const char *c)
{
	size_t	i;

	i = 0;
	while (c[i])
		if (*s != c[i++])
			return ((char*)s);
	while (*(s++))
	{
		i = 0;
		while (c[i])
			if (*s != c[i++])
				return ((char*)s);
	}
	return (0);
}

static char		**ft_desalloc(char ***p, size_t i)
{
	while (--i)
		free(*p[i]);
	free(*p[0]);
	free(*p);
	return (0);
}

char			**ft_strssplit(char const *s, char const *c)
{
	size_t	len;
	size_t	se[2];
	size_t	i;
	char	**p;

	if (!s || !c)
		return (0);
	s = ft_strunchr(s, c);
	len = null_prot_nbr_word(s, c);
	if (!(p = (char**)malloc((len + 1) * sizeof(*p))))
		return (0);
	se[0] = 0;
	se[1] = 0;
	i = 0;
	while (i < len)
	{
		start_and_end(s, c, &se[0], &se[1]);
		if (!(p[i++] = ft_strsub(s, (unsigned int)se[0], se[1] - se[0])))
			return (ft_desalloc(&p, i));
	}
	p[i] = 0;
	return (p);
}
