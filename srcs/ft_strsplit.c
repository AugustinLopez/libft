/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulopez <aulopez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 09:25:07 by aulopez           #+#    #+#             */
/*   Updated: 2019/07/06 11:40:17 by aulopez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static inline char		*trim_start(const char *s, int c)
{
	if (*s != c)
		return ((char*)s);
	while (*(s++))
		if (*s != c)
			return ((char*)s);
	return (NULL);
}

static inline char		**free_all(char ***ppc, size_t i)
{
	while (--i)
		free(*ppc[i]);
	free(*ppc[0]);
	free(*ppc);
	return (NULL);
}

static inline size_t	nbr_word(const char *s, char c)
{
	size_t	word;

	if (!*s)
		return (0);
	word = 1;
	while (*++s)
		if (*s != c && *(s - 1) == c)
			++word;
	return (word);
}

static inline void		find_word(const char *s, char c,
							size_t *start, size_t *end)
{
	*start = *end;
	while (s[*start])
	{
		if (s[*start] == c)
			++*start;
		else
		{
			*end = *start;
			while (s[*end] && s[*end] != c)
				++*end;
			return ;
		}
	}
}

char					**ft_strsplit(char const *s, char c)
{
	size_t	n;
	size_t	start;
	size_t	end;
	size_t	i;
	char	**ppc;

	if (!c || !(s = trim_start(s, c)))
		return (NULL);
	n = nbr_word(s, c);
	if (!(ppc = (char**)malloc((n + 1) * sizeof(*ppc))))
		return (0);
	start = 0;
	end = 0;
	i = 0;
	while (i < n)
	{
		find_word(s, c, &start, &end);
		if (!(ppc[i++] = ft_strsub(s, (unsigned int)start, end - start)))
			return (free_all(&ppc, i));
	}
	ppc[n] = 0;
	return (ppc);
}
