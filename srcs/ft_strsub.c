/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulopez <aulopez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 09:25:18 by aulopez           #+#    #+#             */
/*   Updated: 2019/07/06 11:09:45 by aulopez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*pc;

	if (!(pc = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	ft_strncpy(pc, s + start, len);
	pc[len] = 0;
	return (pc);
}
