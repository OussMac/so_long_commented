CC= cc
FLAGS= -Wall -Werror -Wextra
HEADER= so_long.h

SRC=	so_long.c print_error.c print_utils.c get_next_line.c \
		get_next_line_utils.c input_utils.c process_map.c

OBJ=$(SRC:.c=.o)

NAME= so_long

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $@

%.o: %.c $(HEADER)
	$(CC) -c $< -o $@

fclean: clean
	rm -f $(NAME)

clean:
	rm -f $(OBJ)

re: fclean all

.PHONY: clean