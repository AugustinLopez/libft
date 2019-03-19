/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atozu.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulopez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 17:00:52 by aulopez           #+#    #+#             */
/*   Updated: 2018/12/21 11:18:12 by aulopez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t			ft_atozu(const char *src)
{
	size_t	ui;
	size_t	limit;
	size_t	tmp;

	limit = -1;
	ui = 1;
	while ((limit /= 10))
		ui *= 10;
	tmp = -1;
	limit = ui / 10;
	while ((*src >= 9 && *src <= 13) || *src == ' ')
		src++;
	ui = 0;
	if (*src == '+')
		src++;
	while ('0' <= *src && *src <= '9' && ui < limit)
		ui = ui * 10 + *(src++) - '0';
	if ('0' <= *src && *src <= '9')
	{
		if (ui > tmp / 10 || (ui == limit && (size_t)(*src - '0') > tmp % 10))
			return (-1);
		ui = ui * 10 + *src - '0';
	}
	return (ui);
}
