/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulopez <aulopez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 15:02:50 by aulopez           #+#    #+#             */
/*   Updated: 2019/07/06 09:53:48 by aulopez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strncpy(char *restrict s1, const char *restrict s2, size_t n)
{
	char	*pc;
	size_t	len;

	if ((pc = ft_memccpy(s1, s2, 0, n)))
	{
		len = pc - s1;
		ft_bzero(pc, n - len);
	}
	return (s1);
}
