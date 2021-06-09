/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmacquet <kmacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 15:23:14 by kmacquet          #+#    #+#             */
/*   Updated: 2021/06/09 15:29:48 by kmacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (*s++)
		i++;
	return (i);
}

void	ft_free(char *tab)
{
	free(tab);
	tab = NULL;
}

void	ft_error(char *s, char *tab)
{
	write(1, s, ft_strlen(s));
	ft_free(tab);
	exit(1);
}

int	ft_atoi(char *str)
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
