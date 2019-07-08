/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulopez <aulopez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 09:23:08 by aulopez           #+#    #+#             */
/*   Updated: 2019/07/08 11:22:35 by aulopez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

/*
** Basic implementation
*/

/*
**void	ft_strclr(char *s)
**{
**	while (*s)
**		*s++ = 0;
**}
*/

void	ft_strclr(char *s)
{
	uint64_t	*lls;
	uint64_t	one_each_byte;

	while ((uintptr_t)s & 0x7)
	{
		if (!*s)
			return ;
		*s++ = 0;
	}
	lls = (uint64_t *)s;
	one_each_byte = 0x0101010101010101L;
	while (1)
	{
		if (((*lls - one_each_byte) & ~*lls) & (one_each_byte << 7))
			break ;
		*lls++ = 0;
	}
	s = (char *)lls;
	while (*s)
		*s++ = 0;
}
