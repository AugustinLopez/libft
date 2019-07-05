/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulopez <aulopez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 14:00:55 by aulopez           #+#    #+#             */
/*   Updated: 2019/07/05 23:20:28 by aulopez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

static inline int	check_long(long unsigned int ui, const char sign)
{
	if (sign == -1 && ui > LLONG_MAX)
		return (0);
	if (sign == 1 && ui > LLONG_MAX - 1)
		return (-1);
	return (ui * sign);
}

int					ft_atoi(const char *src)
{
	char				sign;
	long unsigned int	ui;

	while ((*src >= 9 && *src <= 13) || *src == ' ')
		src++;
	ui = 0;
	sign = 1;
	if (*src == '+' || *src == '-')
		sign = (*(src++) == '+') ? 1 : -1;
	while ('0' <= *src && *src <= '9')
		ui = ui * 10 + *(src++) - '0';
	return (check_long(ui, sign));
}
