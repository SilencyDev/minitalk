/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmacquet <kmacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 17:03:12 by kmacquet          #+#    #+#             */
/*   Updated: 2021/06/09 15:33:53 by kmacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

static int	g_r = 0;

void	send_signal(char *tab, int pid)
{
	int	j;

	j = __CHAR_BIT__ - 1;
	while (j >= 0)
	{
		usleep(100);
		g_r = 0;
		if (tab[j] == '0')
			if (kill(pid, SIGUSR1) == -1)
				ft_error("Error: pid invalid\n", tab);
		if (tab[j] == '1')
			if (kill(pid, SIGUSR2) == -1)
				ft_error("Error: pid invalid\n", tab);
		j--;
		while (!g_r)
			;
	}
}

char	*char_to_binary(char c, int pid)
{
	char	*tab;
	int		i;

	i = __CHAR_BIT__ - 1;
	tab = malloc(__CHAR_BIT__ + 1);
	if (!tab)
		ft_error("Error : malloc failed", NULL);
	tab[8] = 0;
	while (i >= 0)
	{
		tab[i] = (c % 2) + '0';
		c /= 2;
		i--;
	}
	send_signal(tab, pid);
	return (tab);
}

void	to_one(int i)
{
	(void)i;
	g_r = 1;
}

int	main(int ac, char **av)
{
	int		j;
	char	*tab;
	int		pid;

	j = 0;
	g_r = 0;
	signal(SIGUSR2, to_one);
	if (ac != 3)
		ft_error("Error : invalid arguments\n", NULL);
	pid = ft_atoi(av[1]);
	while (*av[2])
		tab = char_to_binary(*av[2]++, pid);
	j = 0;
	while (j++ < 8)
	{
		usleep(100);
		g_r = 0;
		if (kill(pid, SIGUSR1) == -1)
			ft_error("Error: pid invalid\n", tab);
		while (!g_r)
			;
	}
	free(tab);
	return (0);
}
