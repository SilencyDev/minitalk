/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmacquet <kmacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 17:54:55 by kmacquet          #+#    #+#             */
/*   Updated: 2021/06/09 15:29:09 by kmacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# define SIGHUP		1	/* Hangup the process */
# define SIGINT		2   /* Interrupt the process */
# define SIGQUIT	3   /* Quit the process */
# define SIGILL		4   /* Illegal instruction. */
# define SIGTRAP	5   /* Trace trap. */
# define SIGABRT	6   /* Abort. */
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <signal.h>

int		ft_strlen(char *s);
void	ft_free(char *tab);
void	ft_error(char *s, char *tab);
int		ft_atoi(char *str);

#endif