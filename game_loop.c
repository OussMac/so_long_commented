#include "so_long.h"

void    build_map(char *map_name, t_parse *parse, int *fd)
{
    char    **grid;

    *fd = open(map_name, O_RDONLY);
	if (*fd == -1)
    {
        print_error(OP_FAIL);
		exit(EXIT_FAILURE);
    }
    grid = create_2d_grid(*fd, parse);
    free_grid(grid);
    close(*fd);
}

void    game_loop(char *map_name, t_parse *parse, int *fd)
{
    build_map(map_name, parse, fd);
}