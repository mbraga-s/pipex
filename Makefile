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

SRCS = pipex pipex_utils pipex_utils_2\
	./libft/ft_bzero ./libft/ft_calloc ./libft/ft_split ./libft/ft_strjoin\
	./libft/ft_strlcpy ./libft/ft_strlen ./libft/ft_strncmp ./libft/ft_substr \
	./libft/ft_strdup ./libft/ft_memcpy \
	./ftprintf/ft_numbers ./ftprintf/ft_printf ./ftprintf/ft_strings\

LIB = $(NAME).a

CC = cc
CFLAGS = -Wall -Wextra -Werror -g #-fsanitize=address

RM = rm -fr

all: $(NAME)

$(NAME): $(LIB)
		$(CC) $(CFLAGS) $(LIB) -o $(NAME)

$(LIB): $(SRCS:=.o)
		ar rc $(LIB) $(SRCS:=.o)

clean:
	$(RM)	$(SRCS:=.o)

lclean:
	$(RM)	$(LIB)

fclean: clean lclean
		$(RM)	$(NAME)

re:	fclean	$(NAME)

.PHONY: clean fclean re