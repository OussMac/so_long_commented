CC= cc
FLAGS= -Wall -Werror -Wextra -O3 
HEADER= so_long.h

SRC=	so_long.c print_error.c print_utils.c get_next_line.c \
		get_next_line_utils.c input_utils.c process_map.c \
		process_utils.c parse_path.c game_loop.c build_map_utils.c \
		game_loop_utils.c build_map_helpers.c ft_itoa.c

OBJ=$(SRC:.c=.o)

NAME= so_long

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -I. .mlx_linux/libmlx.a -lXext -lX11 -lm -o $@

%.o: %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

fclean: clean
	rm -f $(NAME)

clean:
	rm -f $(OBJ)

re: fclean all

.PHONY: clean