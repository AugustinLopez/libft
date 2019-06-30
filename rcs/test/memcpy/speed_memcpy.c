/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   speed_memcpy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulopez <aulopez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 09:37:16 by aulopez           #+#    #+#             */
/*   Updated: 2019/06/30 23:09:11 by aulopez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h>
# include <time.h>
# include <string.h>
# include <stdlib.h>
# include <libft.h>

void	memcpy_speed_test(int len, int second, char *dst, char *src1,
							char *src2, void *(mem)(void *, const void *, size_t))
{
	clock_t			chrono;
	clock_t			start;
	unsigned char	chr;
	size_t			i;

	chrono = 0;
	chr = 0;
	i = 0;
	memset(src1, 0xff, len);
	memset(src2, 0, len);
	memset(dst, 0, len);
	start = clock();
	while (chrono < second * CLOCKS_PER_SEC)
	{
		if (i % 2)
			mem(dst, src1, len);
		else
			mem(dst, src2, len);
		i++;
		chrono = clock() - start;
	}
	printf("%zu\n", i);
}

int	main(int ac, char **av)
{
	int		size;
	char	*buff;
	char	*src1;
	char	*src2;

	if (ac < 2)
		return (0);
	buff = (char *)malloc(sizeof(*buff) * (1000000 + 1));
	src1 = (char *)malloc(sizeof(*buff) * (1000000 + 7));
	src2 = (char *)malloc(sizeof(*buff) * (1000000 + 7));
	if (buff && src1 && src2)
	{
		size = atoi(av[1]);
		printf("ft_memcpy: ");
		memcpy_speed_test(size, 5, buff, src1 + 5, src2 + 3, *ft_memcpy);
		printf("   memcpy: ");
		memcpy_speed_test(size, 5, buff, src1 + 5, src2 + 3, *memcpy);
	}
	buff ? free(buff) : (void)0;
	src1 ? free(src1) : (void)0;
	src2 ? free(src2) : (void)0;
	return (0);
}
