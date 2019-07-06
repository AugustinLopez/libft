/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulopez <aulopez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 10:29:03 by aulopez           #+#    #+#             */
/*   Updated: 2019/07/06 09:35:02 by aulopez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*pc;
	size_t	n;

	n = ft_strlen(s);
	if (!(pc = (char *)malloc(sizeof(char) * (n + 1))))
		return (0);
	return (ft_memcpy(pc, s, n + 1));
}
