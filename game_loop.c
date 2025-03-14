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
    game->blocks.catr = mlx_xpm_file_to_image(game->mlx, CATR, &game->pxl, &game->pxl);
    game->blocks.catl = mlx_xpm_file_to_image(game->mlx, CATL, &game->pxl, &game->pxl);
    game->blocks.catu = mlx_xpm_file_to_image(game->mlx, CATU, &game->pxl, &game->pxl);
    game->blocks.catd = mlx_xpm_file_to_image(game->mlx, CATD, &game->pxl, &game->pxl);
    game->blocks.food = mlx_xpm_file_to_image(game->mlx, FOOD, &game->pxl, &game->pxl);
    game->blocks.exit_c = mlx_xpm_file_to_image(game->mlx, EXITC, &game->pxl, &game->pxl);
    game->blocks.exit_o = mlx_xpm_file_to_image(game->mlx, EXITO, &game->pxl, &game->pxl);
    if (!game->blocks.grass || !game->blocks.cobble
        || !game->blocks.cobble_t || !game->blocks.catr || !game->blocks.catl 
        || !game->blocks.catu || !game->blocks.catd || !game->blocks.food
        || !game->blocks.exit_c || !game->blocks.exit_o)
    {
        print_error(IMAGE);
        clean_up(game);
    }
}

static void init_window(t_parse *parse, t_game *game)
{
    game->mlx = mlx_init();
    if (!game->mlx)
    {
        ft_putstr_fd("Error\nFailed To Initalize MLX Instance.\n", 2);
        exit (EXIT_FAILURE);
    }
    game->map_w = parse->x_max * PIXELS;
    game->map_h = parse->y_max * PIXELS;
    game->blocks_x = parse->x_max;
    game->blocks_y = parse->y_max;
    game->win = mlx_new_window(game->mlx, game->map_w, game->map_h, TITLE);
    if (!game->win)
    {
        mlx_destroy_display(game->mlx);
        free(game->mlx);
        ft_putstr_fd("Error\nFailed To Open Window.\n", 2);
        exit (EXIT_FAILURE);
    }
}

static void    build_map(char *map_name, t_parse *parse, t_game *game, int fd)
{
    fd = open(map_name, O_RDONLY);
	if (fd == -1)
    {
        print_error(OP_FAIL);
        mlx_destroy_window(game->mlx, game->win);
        mlx_destroy_display(game->mlx);
        free(game->mlx);
		exit(EXIT_FAILURE);
    }
    game->map = create_2d_grid(fd, parse);
    close(fd);
    game->moves = 0;
    game->player.p_x = parse->player_x;
    game->player.p_y = parse->player_y;
    game->door_x = parse->door_x;
    game->door_y = parse->door_y;
    game->food = parse->c_count;
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