/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulopez <aulopez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 09:26:08 by aulopez           #+#    #+#             */
/*   Updated: 2019/09/04 17:28:04 by aulopez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

ssize_t	ft_putendl_fd(char const *s, int fd)
{
	ssize_t	ret;

	if ((ret = write(fd, s, ft_strlen(s))) == -1)
		return (-1);
	if (write(fd, "\n", 1) == -1)
		return (-1);
	return (ret + 1);
}
