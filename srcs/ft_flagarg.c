/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flagarg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulopez <aulopez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 10:56:56 by aulopez           #+#    #+#             */
/*   Updated: 2019/06/07 10:10:12 by aulopez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <libft.h>

/*
** FT_FLAGARG:
** Basic setup of binary flag for mono-letter argument.
**
** BEHAVIOR:
** - ft_flagarg should be called before attempting to modify ac or av values.
** - *flag should be set prior to launching ft_flagarg.
** - *option should contains up to 32 different characters. Repetition are
** ignored and should be avoided. Only base-ascii characters should be provided.
** The `-` character is reserved: using it as an option may result in undefined
** behavior.
** - Starting from the first argument provided, the function continue as long
** as the current and next argument are an "option".
** - An "option" starts with a `-` & contains at least one additional character.
** The function return the position of the first non "option" argument, or 0
** If it encounters an invalid "option".
** - A `--` without additional character ends the function even if possible
** "option" are still available. Additional characters should result in an
** invalid "option".
** - If a character is a valid option, it will activate a bit depending on the
** position in the string *option. See EXAMPLE SETUP for reference.
** - I advice using # define to quickly access relevant bit.
**
** EXAMPLE SETUP:
** # define OPTION "abC1"
** # define OPTION_A (1 << 0)
** # define OPTION_B (1 << 1)
** # define OPTION_CC (1 << 2)
** # define OPTION_1 (1 << 3)
*/

int					ft_flagarg(int ac, char **av, uint32_t *flag, char *options)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (++i < ac && av[i][0] == '-' && av[i][1])
	{
		if (av[i][1] == '-' && !av[i][2])
		{
			if (!(av[i + 1]))
				return (0);
			return (i + 1);
		}
		tmp = av[i];
		while (*(++tmp))
		{
			if (!(j = ft_strchri(options, *tmp)))
				return (0);
			*flag |= (1 << (j - 1));
		}
	}
	return (i);
}
