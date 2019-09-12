/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulopez <aulopez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 13:09:30 by aulopez           #+#    #+#             */
/*   Updated: 2019/07/03 13:09:30 by aulopez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTING_H
# define TESTING_H

# define SUCCESS 0
# define FAILURE -1
# define ERROR -2
# define FAIL_1 1
# define FAIL_2 2
# define FAIL_3 3
# define FAIL_4 4
# define NO_CRASH 10

char	**g_av;
void	crash_unexpected(int signo);
void	crash_expected(int signo);
void	*protected_memory(int i);
int		setup(int ac, char **av);
int		cleanup(int ret, char **av);

#endif
