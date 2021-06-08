/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmacquet <kmacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 17:54:55 by kmacquet          #+#    #+#             */
/*   Updated: 2021/06/08 19:16:00 by kmacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <signal.h>
# define SIGHUP  1   /* Hangup the process */ 
# define SIGINT  2   /* Interrupt the process */ 
# define SIGQUIT 3   /* Quit the process */ 
# define SIGILL  4   /* Illegal instruction. */ 
# define SIGTRAP 5   /* Trace trap. */ 
# define SIGABRT 6   /* Abort. */
#endif