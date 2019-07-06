/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulopez <aulopez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 09:24:40 by aulopez           #+#    #+#             */
/*   Updated: 2019/07/06 11:02:21 by aulopez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t			len;
	char			*p;
	char			*cbuf;
	unsigned int	i;

	len = ft_strlen((char*)s);
	if (!(p = ft_strnew(len)))
		return (0);
	cbuf = p;
	i = 0;
	while (len--)
		*(cbuf++) = f(i++, *(s++));
	return (p);
}
