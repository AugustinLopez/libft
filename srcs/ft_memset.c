/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulopez <aulopez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 14:56:45 by aulopez           #+#    #+#             */
/*   Updated: 2019/06/14 09:48:41 by aulopez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdint.h>

/*
** FT_MEMSET:
** <string.h> for size_t, <stdint.h> for uint64_t
**
** if len < 8, we set 1 byte per iteration.
** if len >= 8:
** - We first need to align the memory: the pointer address value must be a
**   multiple of 8. We just have to check the last 3 bit. The alignment will
**   take up to 7 iterations, with 1 byte set per operation.
** - We create a mask and use it to set 8 bytes per iteration. This allow for
** a faster setup of big block of memory.
** - When less than 8 bytes to set remains, we set 1 byte per iteration.
*/

static inline uint64_t	set_memory(uint64_t **magic, void *pc, int c)
{
	uint64_t	bmagic;

	bmagic = c & 0xff;
	bmagic = (bmagic << 8) | bmagic;
	bmagic = (bmagic << 16) | bmagic;
	bmagic = (bmagic << 32) | bmagic;
	*magic = (uint64_t *)pc;
	return (bmagic);
}

void					*ft_memset(void *b, int c, size_t len)
{
	uint64_t	bmagic;
	uint64_t	*magic;
	char		*pc;

	pc = (char *)b;
	if (len >= 8)
	{
		while (((size_t)pc & 0x7))
		{
			*pc++ = c;
			--len;
		}
		bmagic = set_memory(&magic, (void *)pc, c);
		while (len >= 8)
		{
			*magic++ = bmagic;
			len -= 8;
		}
		pc = (char *)magic;
	}
	while (len--)
		*pc++ = c;
	return (b);
}
