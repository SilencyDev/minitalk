# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmacquet <kmacquet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/07 16:53:03 by kmacquet          #+#    #+#              #
#    Updated: 2021/06/09 12:48:26 by kmacquet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I./includes
NAME1 = client
NAME2 = server
SRCS1 = srcs/client.c
SRCS2 = srcs/server.c
SRCS1BON = srcs/client_bonus.c
SRCS2BON = srcs/server_bonus.c
RM = rm -rf

ifdef WITH_BONUS
	OBJS1 = $(SRCS1BON:.c=.o)
	OBJS2 = $(SRCS2BON:.c=.o)
else
	OBJS1 = $(SRCS1:.c=.o)
	OBJS2 = $(SRCS2:.c=.o)
endif

all : $(NAME1) $(NAME2)

bonus :
	make WITH_BONUS=1 all

$(NAME1) : $(OBJS1)
	$(CC) $(CFLAGS) $(OBJS1) -o $(NAME1)

$(NAME2) : $(OBJS2)
	$(CC) $(CFLAGS) $(OBJS2) -o $(NAME2)

clean :
	$(RM) $(OBJS1)
	$(RM) $(OBJS2)
	$(RM) $(OBJS1BON)
	$(RM) $(OBJS2BON)

fclean : clean
	$(RM) $(NAME1)
	$(RM) $(NAME2)

re : fclean all

.PHONY : re fclean clean all