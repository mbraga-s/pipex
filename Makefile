# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbraga-s <mbraga-s@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/23 16:29:01 by mbraga-s          #+#    #+#              #
#    Updated: 2023/05/23 16:29:01 by mbraga-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRCS = main ./libft/ft_split ./libft/ft_strncmp ./libft/ft_strjoin

LIB = $(NAME).a

OLIB = libftprintf libft

CC = cc
CFLAGS = -Wall -Wextra -Werror

RM = rm -fr

all: $(NAME)

$(NAME): lib
		$(CC) $(CFLAGS) $(LIB) $(OLIB:=.a) -o $(NAME)

lib: $(SRCS:=.o)
		ar rc $(LIB) $(SRCS:=.o)

clean:
	$(RM)	$(SRCS:=.o)

lclean:
	$(RM)	$(LIB)

fclean: clean lclean
		$(RM)	$(NAME)

re:	fclean	$(NAME)

.PHONY: clean fclean re