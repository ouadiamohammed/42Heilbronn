# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mouadia <mouadia@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/08 14:21:55 by mouadia           #+#    #+#              #
#    Updated: 2023/10/18 17:35:50 by mouadia          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
AR = ar -rc
SRC = ft_atoi.c ft_isprint.c ft_memmove.c ft_strchr.c ft_strmapi.c ft_toupper.c ft_bzero.c ft_itoa.c \
		ft_memset.c ft_strdup.c ft_strncmp.c ft_calloc.c ft_putchar_fd.c ft_striteri.c \
		ft_strnstr.c ft_isalnum.c ft_putendl_fd.c ft_strjoin.c ft_strrchr.c ft_isalpha.c \
		ft_memchr.c ft_putnbr_fd.c ft_strlcat.c ft_strtrim.c ft_isascii.c ft_memcmp.c ft_putstr_fd.c ft_strlcpy.c \
		ft_substr.c ft_isdigit.c ft_memcpy.c ft_split.c ft_strlen.c ft_tolower.c 

OBJ = $(SRC:.c=.o)

BONUS = ft_lstnew_bonus.c \
		ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
		ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

OBONUS = $(BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		$(AR) $(NAME) $(OBJ)
		ranlib $(NAME)

$(OBJ): $(SRC)
	$(CC) -I ./ $(CFLAGS) -c $(SRC)

$(OBONUS) : $(BONUS)
		$(CC) -I ./ $(CFLAGS) -c $(BONUS)
		$(AR) $(NAME) $(OBONUS) $(OBJ)
		ranlib $(NAME)

bonus: $(OBONUS) $(OBJ)
		
clean:
		$(RM) $(OBJ) $(OBONUS)

fclean: clean
		$(RM) $(NAME)

re: fclean all
