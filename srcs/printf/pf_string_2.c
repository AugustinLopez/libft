/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_string_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulopez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 19:11:45 by aulopez           #+#    #+#             */
/*   Updated: 2019/02/01 19:16:27 by aulopez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void				pf_putchar(t_printf *pf)
{
	unsigned	c;

	c = va_arg(pf->ap, unsigned);
	pf->printed = 1;
	pf->padding = pf->length - 1;
	pf_padding(pf, 0);
	pf_buffer_write(pf, &c, 1);
	pf_padding(pf, 1);
}
