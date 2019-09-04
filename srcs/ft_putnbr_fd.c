/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulopez <aulopez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 09:22:20 by aulopez           #+#    #+#             */
/*   Updated: 2019/09/04 17:21:53 by aulopez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>
#include <unistd.h>

ssize_t		ft_putnbr_fd(int n, int fd)
{
	unsigned int	pow10;
	unsigned int	buf;
	int				iter;
	char			c[LOG_UINT_MAX + 1];
	uint8_t			log;

	log = 0;
	pow10 = 1;
	iter = n;
	while ((iter /= 10))
		++log;
	buf = ++log;
	while (--buf)
		pow10 *= 10;
	buf = n < 0 ? -n : n;
	iter = n < 0 ? 1 : 0;
	c[0] = n < 0 ? '-' : 0;
	while (log--)
	{
		c[iter++] = buf / pow10 + '0';
		buf %= pow10;
		pow10 /= 10;
	}
	return (write(1, c, iter));
}
