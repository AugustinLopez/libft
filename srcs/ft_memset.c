/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulopez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 14:56:45 by aulopez           #+#    #+#             */
/*   Updated: 2019/03/12 16:16:16 by aulopez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned long long	set_memory_block(unsigned long long **magic,
												void *pc,
												int c)
{
	unsigned long long bmagic;

	bmagic = 0xff & c;
	bmagic = (bmagic << 8) | bmagic;
	bmagic = (bmagic << 16) | bmagic;
	bmagic = ((bmagic << 16) << 16) | bmagic;
	*magic = (unsigned long long int *)pc;
	return (bmagic);
}

void						*ft_memset(void *b, int c, size_t len)
{
	unsigned long long	bmagic;
	unsigned long long	*magic;
	unsigned char		*pc;

	magic = NULL;
	pc = (unsigned char *)b;
	while (((unsigned long long)pc & (sizeof(bmagic) - 1)) && len)
	{
		*pc++ = c;
		--len;
	}
	if (len >= 8)
	{
		bmagic = set_memory_block(&magic, (void *)pc, c);
		while (len >= 8)
		{
			*magic++ = bmagic;
			len -= 8;
		}
	}
	pc = magic == NULL ? pc : (unsigned char *)magic;
	while (len--)
		*pc++ = c;
	return (b);
}
