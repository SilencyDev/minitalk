/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmacquet <kmacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 17:03:16 by kmacquet          #+#    #+#             */
/*   Updated: 2021/06/08 20:19:53 by kmacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	ft_putnum(int pid)
{
	char c;

	c = 0;
	if (pid > 9)
		ft_putnum(pid / 10);
	c = pid % 10 + '0';
	write(STDOUT_FILENO, &c, 1);
}

void	translate_signal(int d)
{
	static int				i = 0;
	static unsigned	char	c = 0;

	c |= d << i++;
	if (i > 7)
	{
		if (c == '\0')
		{
			write(1, "\n", 1);
			write(1, &c, 1);
		}
		else
			write(1, &c, 1);
		c = 0;
		i = 0;
	}
}

void	signal_handler(int sig)
{
	if (sig == SIGUSR1)
		translate_signal(0);
	if (sig == SIGUSR2)
		translate_signal(1);
}

int	main (void)
{
	pid_t pid;

	pid = getpid();
	ft_putnum(pid);
	write(STDOUT_FILENO, "\n", 1);
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (1)
	{
		usleep(125);
	}
}