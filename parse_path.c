#include "so_long.h"

void free_grid(char **grid)
{
    int y;

    y = 0;
    while (grid[y])
        free(grid[y++]);
    free(grid);
}

char    **create_2d_grid(int fd, t_parse *parse)
{
    int     y;
    char    **grid;
    char    *row;

    y = 0;
    grid = (char **) malloc (sizeof(char *) * parse->y_max);
    if (!grid)
    {
        print_error(MALLOC_F);
        close (fd);
        exit (EXIT_FAILURE);
    }
    row = cut_row(get_next_line(fd));
    while (row)
    {
        grid[y++] = row;
        row = cut_row(get_next_line(fd));
    }
    grid[y] = NULL;
    return (grid);
}

int parse_path(char *map_name, t_parse *parse)
{
    int     fd;
    char    **grid;

    fd = open(map_name, O_RDONLY);
	if (fd == -1)
    {
        print_error(OP_FAIL);
		exit(EXIT_FAILURE);
    }
    grid = create_2d_grid(fd, parse);
    free_grid(grid);
    return (fd);
}
