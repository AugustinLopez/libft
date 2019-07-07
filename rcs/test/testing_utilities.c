/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing_utilities.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulopez <aulopez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 13:09:30 by aulopez           #+#    #+#             */
/*   Updated: 2019/07/07 16:11:21 by aulopez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/mman.h>
#include <string.h>

void	crash_unexpected(int signo)
{
	write(1, "\033[31mUnexpected crash\033[39m : ", 29);
	signal(signo, SIG_DFL);
	raise(signo);
}

void	crash_expected(int signo)
{
	if (signo == SIGSEGV)
		write(1, "\033[33mSegfault\033[39m\n", 19);
	else if (signo == SIGBUS)
		write(1, "\033[33mBus error\033[39m\n", 20);
	exit(EXIT_SUCCESS);
}

int		setup(int ac, char **av)
{
	if (ac < 4 || !av[1][0] || !av[2][0] || !av[3][0])
		return (0);
	signal(SIGBUS, crash_unexpected);
	signal(SIGSEGV, crash_unexpected);
	signal(SIGABRT, crash_unexpected);
	signal(SIGFPE, crash_unexpected);
	signal(SIGILL, crash_unexpected);
	signal(SIGTRAP, crash_unexpected);
	signal(SIGSYS, crash_unexpected);
	signal(SIGXCPU, crash_unexpected);
	signal(SIGXFSZ, crash_unexpected);
	signal(SIGQUIT, crash_unexpected);
	return (1);
}

int		cleanup(int ret)
{
	if (!ret)
		write(1, "\033[32mSuccess\033[39m\n", 18);
	else if (ret == -1)
		write(1, "\033[33mInvalid\033[39m\n", 18);
	else if (ret == 10)
		write(1, "\033[33mNo crash\033[39m\n", 19);
	else
		write(1, "\033[31mFailure\033[39m\n", 18);
	return (ret);
}

void	*protected_memory(int i)
{
	void	*m;

	m = mmap(0, i * 2, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	if (!m)
		return (NULL);
	memset(m, 0xff, i * 2);
	mprotect(m + i, i, PROT_NONE);
	return (m);
}
