/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulopez <aulopez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 09:22:20 by aulopez           #+#    #+#             */
/*   Updated: 2019/08/06 11:04:43 by aulopez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void		ft_putnbr_fd(int n, int fd)
{
	unsigned int	pow10;
	unsigned int	log;
	unsigned int	buf;
	int				ret;
	char			c;

	log = 0;
	pow10 = 1;
	ret = n;
	while ((ret /= 10))
		++log;
	buf = ++log;
	while (--buf)
		pow10 *= 10;
	buf = n < 0 ? -n : n;
	ret = n < 0 ? write(fd, "-", 1) : 0;
	while (log--)
	{
		c = buf / pow10 + '0';
		ret += write(fd, &c, 1);
		buf %= pow10;
		pow10 /= 10;
	}
	(void)ret;
}
