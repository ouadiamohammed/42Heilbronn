NAME = libftprintf.a

CFLAGS = -Wall -Wextra -Werror

LIB = ar -rc

RM = rm -rf

SRC =	ft_nlhex.c ft_nuhex.c ft_printf.c ft_putnbr.c ft_putstr.c \
		ft_putchar.c ft_printadd.c ft_putn.c
	   

OBJS =	$(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
		$(LIB) $(NAME) $(OBJS)

clean :
		$(RM) $(OBJS)

fclean : clean
		$(RM) $(NAME)

re : fclean all
