# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mouadia <mouadia@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/08 14:21:55 by mouadia           #+#    #+#              #
#    Updated: 2023/10/09 14:46:02 by mouadia          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
AR = ar -rcs
SRC =  $(wildcard ./*.c) #khas nfhamha
vpath %.c . #hadi tahia

OBJ = $(addprefix ./, $(notdir $(SRC:.c=.o))) #hadi

all: $(NAME)

$(NAME) : $(OBJ)
			$(AR) $(NAME) $(OBJ)

$(OBJ): $(SRC)
		$(CC) -I ./ $(CFLAGS) -c $(SRC)

clean:
		$(RM) $(OBJ)

fclean:	clean
		$(RM) $(NAME)

re: fclean all
