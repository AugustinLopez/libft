/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulopez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 09:58:36 by aulopez           #+#    #+#             */
/*   Updated: 2019/03/18 15:35:52 by aulopez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

static int		ft_lstdelone_neuron(t_list **alst, int fd)
{
	t_list		*after;
	t_list		*previous;

	previous = *alst;
	after = (*alst)->next;
	if ((int)previous->zu == fd)
	{
		ft_lstdelone(&previous, *ft_lstfree);
		*alst = after;
		return (0);
	}
	while (after)
	{
		if ((int)after->zu == fd)
		{
			previous->next = after->next;
			ft_lstdelone(&after, *ft_lstfree);
			return (0);
		}
		after = after->next;
		previous = previous->next;
	}
	return (0);
}

static int		free_mem_and_exit(int option, t_list **neur, char **tmp,
									t_list **alst)
{
	if (!option)
	{
		if (tmp && *tmp)
			free(*tmp);
		if (alst && *alst)
			ft_lstdel(alst, *ft_lstfree);
		return (-1);
	}
	else
	{
		free((*neur)->pv);
		(*neur)->pv = *tmp;
	}
	return (0);
}

static int		get_from_memory(t_list **neuron, t_list **memory,
					int fd, char **line)
{
	t_list		*temp;
	char		dummy[1];

	if ((fd < 0 || line == NULL || read(fd, dummy, 0) < 0))
		return (-1);
	temp = *memory;
	while (temp)
	{
		if ((int)temp->zu == fd)
		{
			*neuron = temp;
			if ((*neuron)->pv && ft_strchr((char*)((*neuron)->pv), '\n'))
				return (1);
			return (0);
		}
		temp = temp->next;
	}
	if (!(*neuron = ft_lstnew("", 1)))
		return (-1);
	(*neuron)->zu = fd;
	ft_lstadd(memory, *neuron);
	*neuron = *memory;
	return (0);
}

static int		ft_new_line(char **s, char **line, t_list **memory, int keep_n)
{
	char	*temp;
	int		len;

	len = 0;
	while ((*s)[len] != '\n' && (*s)[len] != '\0')
		len++;
	if ((*s)[len] == '\n')
	{
		if (!(*line = ft_strsub(*s, 0, len + keep_n)))
			return (free_mem_and_exit(0, 0, 0, memory));
		if (!(temp = ft_strdup(*s + len + 1)))
			return (free_mem_and_exit(0, 0, 0, memory));
		free(*s);
		*s = temp;
		if (!((*s)[0]))
			ft_strdel(s);
	}
	else if ((*s)[len] == '\0')
	{
		if (!(*line = ft_strdup(*s)))
			return (free_mem_and_exit(0, 0, 0, memory));
		ft_strdel(s);
	}
	return (1);
}

int				ft_gnl(const int fd, char **line, int keep_n)
{
	static t_list	*memory;
	t_list			*neur;
	char			buf[4096 + 1];
	char			*tmp;
	int				ret;

	if (!(ret = get_from_memory(&neur, &memory, fd, line)))
	{
		while ((ret = read(fd, buf, 4096)) && ret != -1)
		{
			buf[ret] = '\0';
			if (!(tmp = ft_strjoin(neur->pv, buf))
			|| ft_strlen(buf) != (unsigned int)ret)
				return (free_mem_and_exit(0, 0, 0, &memory));
			(void)free_mem_and_exit(1, &neur, &tmp, 0);
			if (ft_strchr(buf, '\n'))
				break ;
		}
	}
	if (ret < 0)
		return (free_mem_and_exit(0, 0, 0, &memory));
	if (ret == 0 && (neur->pv == 0 || ((char*)(neur->pv))[0] == 0))
		return (ft_lstdelone_neuron(&memory, fd));
	return (ft_new_line((char**)&(neur->pv), line, &memory, (keep_n != 0)));
}
