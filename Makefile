CC= cc
FLAGS= -Wall -Werror -Wextra
HEADER= so_long.h

SRC=	so_long.c print_error.c print_utils.c get_next_line.c \
		get_next_line_utils.c input_utils.c process_map.c \
		process_utils.c parse_path.c game_loop.c

OBJ=$(SRC:.c=.o)

NAME= so_long
MLX=minilibx-linux/libmlx_Linux.a

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -L$(MLX) $(MLX) -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $@

%.o: %.c $(HEADER)
	$(CC) $(FLAGS) -I/usr/include -I$(MLX) -O3 -c $< -o $@

fclean: clean
	rm -f $(NAME)

clean:
	rm -f $(OBJ)

re: fclean all

.PHONY: clean