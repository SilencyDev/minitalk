/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmacquet <kmacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 17:03:12 by kmacquet          #+#    #+#             */
/*   Updated: 2021/06/08 20:17:24 by kmacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

int					ft_atoi(char *str)
{
	unsigned int	i;
	int				posneg;
	int				result;

	i = 0;
	result = 0;
	posneg = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			posneg = -1;
	while (str[i] >= '0' && str[i] <= '9')
		result = result * 10 + (str[i++] - '0');
	return (result * posneg);
}

char *char_to_binary(char c)
{
	char	*tab;
	int		i;

	i = __CHAR_BIT__ - 1;
	tab = malloc(__CHAR_BIT__ + 1);
	if (!tab)
		;
	tab[8] = 0;
	while (i >= 0)
	{
		tab[i] = (c % 2) + '0';
		c /= 2;
		i--;
	}
	return (tab);
}

int	main(int ac, char **av)
{
	int		j;
	char	*tab;
	int		pid;

	j = 0;
	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		while (*av[2])
		{
			printf("[%c]\n", *av[2]);
			tab = char_to_binary(*av[2]++);
			printf("%s\n", tab);
			j = 8 - 1;
			while (j >= 0)
			{
				if (tab[j] == '0')
				{
					kill(pid, SIGUSR1);
					usleep(200);
				}
				if (tab[j] == '1')
				{
					kill(pid, SIGUSR2);
					usleep(200);
				}
				j--;
			}
		}
		j = 0;
		while (j++ < 8)
		{
			kill(pid, SIGUSR1);
			usleep(200);
		}
	}
}