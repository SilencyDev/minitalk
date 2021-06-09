/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmacquet <kmacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 17:03:12 by kmacquet          #+#    #+#             */
/*   Updated: 2021/06/09 16:50:11 by kmacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

static int	g_r = 0;

void	send_signal(char c, int pid)
{
	int	j;

	j = 0;
	while (j < 8)
	{
		usleep(100);
		g_r = 0;
		if ((c >> j) & 1)
		{
			if (kill(pid, SIGUSR2) == -1)
				ft_error("Error: pid invalid\n");
		}
		else
		{
			if (kill(pid, SIGUSR1) == -1)
				ft_error("Error: pid invalid\n");
		}
		j++;
		while (!g_r)
			;
	}
}

void	to_one(int i)
{
	(void)i;
	g_r = 1;
}

int	main(int ac, char **av)
{
	int		j;
	int		pid;

	j = -1;
	g_r = 0;
	signal(SIGUSR2, to_one);
	if (ac != 3)
		ft_error("Error : invalid arguments\n");
	pid = ft_atoi(av[1]);
	while (av[2][++j])
		send_signal(av[2][j], pid);
	j = 0;
	while (j++ < 8)
	{
		usleep(100);
		g_r = 0;
		if (kill(pid, SIGUSR1) == -1)
			ft_error("Error: pid invalid\n");
		while (!g_r)
			;
	}
	return (0);
}
