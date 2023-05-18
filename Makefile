# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbraga-s <mbraga-s@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/18 19:09:31 by mbraga-s          #+#    #+#              #
#    Updated: 2023/05/18 19:09:31 by mbraga-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRCS = main

LIB = $(NAME).a

OLIB = libftprintf libft

CC = cc
CFLAGS = -Wall -Wextra -Werror

RM = rm -fr

all: $(NAME)

$(NAME): lib
		$(CC) $(CFLAGS) $(LIB) $(OLIB) -o $(NAME)

lib: $(SRCS:=.o)
		ar rc $(LIB).a $(SRCS:=.o)

clean:
	$(RM)	$(SRCS:=.o)

lclean:
	$(RM)	$(LIB)

fclean: clean lclean
		$(RM)	$(NAME)

re:	fclean	$(NAME)

.PHONY: clean fclean re