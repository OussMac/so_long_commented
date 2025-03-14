#include "so_long.h"

// for testing.
void    print_grid(char **grid)
{
    int y;

    y = 0;
    while (grid[y])
        printf("%s\n",(grid[y++]));
}

void    free_grid(char **grid)
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
    grid = (char **) malloc (sizeof(char *) * (parse->y_max + 1));
    if (!grid)
    {
        print_error(MALLOC_F);
        close (fd);
        exit (EXIT_FAILURE);
    }
    row = cut_row(get_next_line(fd));
    while (y < parse->y_max)
    {
        grid[y++] = row;
        row = cut_row(get_next_line(fd));
    }
    grid[y] = NULL;
    return (grid);
}

void    fill(char **grid, t_pos p, t_parse *prs)
{
    if (p.x < 0 || p.y < 0 || p.x >= prs->x_max || p.y >= prs->y_max)
        return ;
    if (grid[p.y][p.x] == '1' || grid[p.y][p.x] == 'V')
        return ;
    if (grid[p.y][p.x] == 'C')
        prs->found_c++;
    if (grid[p.y][p.x] == 'E')
    {
        prs->door_x = p.x;
        prs->door_y = p.y;
        prs->found_e++;
    }
    grid[p.y][p.x] = 'V';
    fill(grid, (t_pos){p.x + 1, p.y}, prs);
    fill(grid, (t_pos){p.x - 1, p.y}, prs);
    fill(grid, (t_pos){p.x, p.y + 1}, prs);
    fill(grid, (t_pos){p.x, p.y - 1}, prs);
}

void    flood_fill(char **grid, t_pos player, t_parse *parse, int fd)
{
    bool    error;

    error = false;
    fill(grid, player, parse);
    if (parse->found_c != parse->c_count)
        error = true;
    if (parse->found_e != parse->e_count)
        error = true;
    if (error)
    {
        print_error(PATH_BLOCKED);
        close(fd);
        free_grid(grid);
        exit(EXIT_FAILURE);
    }
}

void    parse_path(char *map_name, t_parse *parse)
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

    flood_fill(grid, (t_pos){parse->player_x , parse->player_y}, parse, fd);
    free_grid(grid);
    close(fd);
}
