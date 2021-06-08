# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmacquet <kmacquet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/07 16:53:03 by kmacquet          #+#    #+#              #
#    Updated: 2021/06/07 18:24:14 by kmacquet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME1 = client
NAME2 = server
SRCS1 = srcs/client.c
SRCS2 = srcs/server.c
OBJS1 = $(SRCS1:.c=.o)
OBJS2 = $(SRCS2:.c=.o)
RM = rm -rf

all : $(NAME1) $(NAME2)

$(NAME1) : $(OBJS1)
	$(CC) $(CFLAGS) $(OBJS1) -o $(NAME1)

$(NAME2) : $(OBJS2)
	$(CC) $(CFLAGS) $(OBJS2) -o $(NAME2)

clean :
	$(RM) $(OBJS1)
	$(RM) $(OBJS2)

fclean : clean
	$(RM) $(NAME1)
	$(RM) $(NAME2)

re : fclean all

.PHONY : re fclean clean all