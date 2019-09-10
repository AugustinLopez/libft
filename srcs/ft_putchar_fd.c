/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulopez <aulopez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 14:46:54 by aulopez           #+#    #+#             */
/*   Updated: 2019/09/04 17:15:07 by aulopez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/types.h>

/*
** https://www.utf8-chartable.de/unicode-utf8-table.pl
*/

/*
** -----------------------------------------------------------------------------
** 000000 --  00007F : 0xxxxxxx
** 000080 --  0007FF : 110xxxxx 10xxxxxx
** 000800 --  00FFFF : 1110xxxx 10xxxxxx 10xxxxxx
** 010000 --  1FFFFF : 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
**
**      0 --     127 : 0aaaaaaa
**    128 --    2047 : 00000aaa aabbbbbb
**   2048 --   65535 : aaaabbbb bbcccccc
**  65536 -- 2097151 : 000aaabb bbbbcccc ccdddddd
** -----------------------------------------------------------------------------
*/

static inline ssize_t	utf8(unsigned int c, int fd)
{
	unsigned char	tmp[4];

	if (c <= 2047)
	{
		tmp[0] = ((c & (0x1f << 6)) >> 6) | 0xc0;
		tmp[1] = (c & 0x3f) | 0x80;
		return (write(fd, tmp, 2));
	}
	else if (c <= 65535)
	{
		tmp[0] = ((c >> 12) & 0xF) | 0xe0;
		tmp[1] = ((c >> 6) & 0x3f) | 0x80;
		tmp[2] = (c & 0x3f) | 0x80;
		return (write(fd, tmp, 3));
	}
	tmp[0] = ((c >> 18) & 7) | 0xf0;
	tmp[1] = ((c >> 12) & 0x3f) | 0x80;
	tmp[2] = ((c >> 6) & 0x3f) | 0x80;
	tmp[3] = (c & 0x3f) | 0x80;
	return (write(fd, tmp, 4));
}

ssize_t					ft_putchar_fd(unsigned int c, int fd)
{
	if (c <= 127)
		return (write(fd, &c, 1));
	else if (c <= 2097151)
		return (utf8(c, fd));
	return (0);
}
