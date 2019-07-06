/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulopez <aulopez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 14:46:54 by aulopez           #+#    #+#             */
/*   Updated: 2019/07/06 11:58:17 by aulopez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
** https://www.utf8-chartable.de/unicode-utf8-table.pl
*/

static inline void	unicode(char c, int fd)
{
	unsigned char	s[2];

	s[1] = c;
	if (s[1] < 0xc0)
		s[0] = 0xc2;
	else
	{
		s[1] -= 0x40;
		s[0] = 0xc3;
	}
	 write(fd, s, 2);
}

void				ft_putchar_fd(char c, int fd)
{
	if (c >= 0)
		write(fd, &c, 1);
	else
		unicode(c, fd);
}
