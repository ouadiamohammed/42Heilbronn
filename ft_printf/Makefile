# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mouadia <mouadia@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/23 20:05:52 by mouadia           #+#    #+#              #
#    Updated: 2023/10/24 09:54:05 by mouadia          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libftprintf.a

CFLAGS = -Wall -Wextra -Werror

LIB = ar -rc

RM = rm -rf

SRC =	ft_printf.c ft_checker.c ft_putchar.c ft_putnbr.c ft_putstr.c \
		ft_put_x.c ft_put_hexup.c ft_putunsigned_int.c ft_put_add.c
	   

OBJS =	$(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
		$(LIB) $(NAME) $(OBJS)

clean :
		$(RM) $(OBJS)

fclean : clean
		$(RM) $(NAME)

re : fclean all
