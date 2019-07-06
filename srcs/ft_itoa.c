/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulopez <aulopez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 09:20:32 by aulopez           #+#    #+#             */
/*   Updated: 2019/07/06 11:44:28 by aulopez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_itoa(int n)
{
	size_t			len;
	int				buf;
	unsigned int	positif;
	char			*p;

	len = (n < 0) + 1;
	buf = n;
	while ((buf /= 10))
		++len;
	if (!(p = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	p[len] = 0;
	if (n < 0)
	{
		p[0] = '-';
		buf = 1;
	}
	positif = n * (1 - 2 * (n < 0));
	while (len > (unsigned int)buf)
	{
		p[--len] = '0' + positif % 10;
		positif /= 10;
	}
	return (p);
}
