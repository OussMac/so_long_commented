#include "so_long.h"

void    clean_up(t_game *game)
{
    free_grid(game->map);
    destroy_images(game);
    mlx_destroy_window(game->mlx, game->win);
    mlx_destroy_display(game->mlx);
    free(game->mlx);
    exit(EXIT_SUCCESS);
}

static void init_images(t_game *game)
{
    game->pxl = PIXELS;
    game->blocks.grass = mlx_xpm_file_to_image(game->mlx, GRASS, &game->pxl, &game->pxl);
    game->blocks.cobble = mlx_xpm_file_to_image(game->mlx, COBBLE, &game->pxl, &game->pxl);
    game->blocks.cobble_t = mlx_xpm_file_to_image(game->mlx, COBBLE_T, &game->pxl, &game->pxl);
    if (!game->blocks.grass || !game->blocks.cobble || !game->blocks.cobble_t )
    {
        print_error(IMAGE);
        clean_up(game);
    }
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
    close(fd);
    init_images(game);
    fill_map(game);
}

void    load_game(char *map_name, t_parse *parse, int fd)
{
    t_game  game;

    init_window(parse, &game);
    build_map(map_name, parse, &game, fd);
    game_loop(&game);
}