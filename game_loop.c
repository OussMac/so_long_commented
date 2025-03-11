#include "so_long.h"

void    clean_up(t_game *game)
{
    mlx_destroy_window(game->mlx, game->win);
    mlx_destroy_display(game->mlx);
    free(game->mlx);
    exit(1);
}

static void init_images(t_game *game)
{
    game->pxl = PIXELS;
    game->blocks.grass = mlx_xpm_file_to_image(game->mlx, GRASS, &game->pxl, &game->pxl);
    game->blocks.cobble = mlx_xpm_file_to_image(game->mlx, COBBLE, &game->pxl, &game->pxl);
    game->blocks.cobble_t = mlx_xpm_file_to_image(game->mlx, COBBLE_T, &game->pxl, &game->pxl);
}

static void init_window(t_parse *parse, t_game *game)
{
    game->mlx = mlx_init();
    game->map_w = parse->x_max * PIXELS;
    game->map_h = parse->y_max * PIXELS;
    game->blocks_x = parse->x_max;
    game->blocks_y = parse->y_max;
    game->win = mlx_new_window(game->mlx, game->map_w, game->map_h, TITLE);
}

static void    build_map(char *map_name, t_parse *parse, t_game *game, int fd)
{
    fd = open(map_name, O_RDONLY);
	if (fd == -1)
    {
        print_error(OP_FAIL);
		exit(EXIT_FAILURE);
    }
    game->map = create_2d_grid(fd, parse);
    init_images(game);
    fill_map(game);
    // print_grid(game->map);
    // free_grid(game->map);
    // close(fd);
}

void    game_loop(char *map_name, t_parse *parse, int fd)
{
    t_game  game;

    init_window(parse, &game);
    build_map(map_name, parse, &game, fd);
    // clean_up(&game);
    mlx_loop(game.mlx);
}