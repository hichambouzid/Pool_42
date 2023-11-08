# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hibouzid <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/01 15:32:11 by hibouzid          #+#    #+#              #
#    Updated: 2023/08/02 21:07:32 by hibouzid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAGS = -Wall -Wextra -Werror -c

FILS = ./srcs/ft_putchar.c ./srcs/ft_swap.c ./srcs/ft_putstr.c ./srcs/ft_strlen.c ./srcs/ft_strcmp.c


OBJS = ./srcs/ft_putchar.o ./srcs/ft_swap.o ./srcs/ft_putstr.o ./srcs/ft_strlen.o ./srcs/ft_strcmp.o

INCLUDS = ./includes/

all: $(NAME)

$(NAME): $(FILS:.c=.o)
	ar -rc libft.a $(FILS:.c=.o)

%.o: %.c
	gcc $(FLAGS) -I $(INCLUDS) $< -o $@ 

clean:
	/bin/rm -rf $(OBJS)

fclean: clean
		rm -rf libft.a

re: fclean all
