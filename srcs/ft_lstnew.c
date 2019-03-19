/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulopez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 11:10:25 by aulopez           #+#    #+#             */
/*   Updated: 2019/03/05 14:17:40 by aulopez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*elem;

	if (!(elem = (t_list*)malloc(sizeof(*elem))))
		return (0);
	if (!content)
	{
		elem->pv = 0;
		elem->zu = 0;
	}
	else
	{
		if (!(elem->pv = malloc(content_size)))
		{
			free(elem);
			return (0);
		}
		ft_memcpy(elem->pv, content, content_size);
		elem->zu = content_size;
	}
	elem->next = 0;
	return (elem);
}
