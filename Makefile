NAME := libftprintf.a

SOURCE = src/ft_digits_ft.o\
	src/ft_digits_ft.c \
	src/ft_printf.c\
	src/ft_printf_conversion.c\
	src/ft_printf_utils.c\
	src/ft_strings_ft.c\

OBJECTS := $(SOURCE:.c=.o)

FLAGS := -Wall -Werror -Wextra -c -o 

$(NAME): $(OBJECTS)
	ar -rcs $(NAME) $(OBJECTS)

%.o: %.c
	cc $(FLAGS) $@ $<

all : $(NAME)

clean :
	rm -rf $(OBJECTS)

fclean : clean
	rm -rf $(NAME)

re : fclean all
