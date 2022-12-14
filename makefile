# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shbi <shbi@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/03 13:05:24 by shbi              #+#    #+#              #
#    Updated: 2022/12/12 23:46:14 by shbi             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	philo
SRCS		=	philo.c	\
				tools.c tools_.c tools__.c
				
OBJS		=	$(SRCS:.c=.o)
HEADR		=	philo.h
CC			=	cc
FLAGS		=	-Wall -Werror -Wextra
RM			=	rm -rf

all			:	$(NAME)
				$(RM) $(OBJS)
$(NAME)		:	$(OBJS)
				$(CC) $(FLAGS) -o $(NAME) $(OBJS)
%.o			:	%.c $(HEADR)
				$(CC) $(FLAGS) -c $< -o $@
clean		:
				$(RM) $(OBJS)
fclean		:	clean
				$(RM) $(NAME)
re			:	fclean all