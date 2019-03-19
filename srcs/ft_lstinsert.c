/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstinsert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulopez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 12:28:44 by aulopez           #+#    #+#             */
/*   Updated: 2018/11/19 12:31:15 by aulopez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstinsert(t_list **alst, t_list *new)
{
	t_list	tmp;

	tmp.zu = (*alst)->zu;
	tmp.pv = (*alst)->pv;
	tmp.next = (*alst)->next;
	(*alst)->zu = new->zu;
	(*alst)->pv = new->pv;
	(*alst)->next = new;
	new->zu = tmp.zu;
	new->pv = tmp.pv;
	new->next = tmp.next;
}
