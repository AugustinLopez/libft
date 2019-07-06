/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulopez <aulopez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 11:43:19 by aulopez           #+#    #+#             */
/*   Updated: 2019/07/06 12:07:06 by aulopez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *temp;

	if (!*alst)
		return ;
	del((*alst)->pv, (*alst)->zu);
	temp = (*alst)->next;
	free(*alst);
	while (temp)
	{
		(*alst) = temp;
		del((*alst)->pv, (*alst)->zu);
		temp = (*alst)->next;
		free(*alst);
	}
	*alst = 0;
}
