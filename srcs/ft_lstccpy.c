/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulopez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 11:10:25 by aulopez           #+#    #+#             */
/*   Updated: 2019/03/05 14:17:40 by aulopez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstccpy(t_list *lst)
{
	t_list	*elem;

	if (!lst || !(elem = ft_lstnew(0,0)))
		return (0);
	elem->pv = ft_strdup(lst->pv);
	elem->zu = lst->zu;
	return (elem);
}
