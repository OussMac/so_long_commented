#include "so_long.h"

void    destroy_images(t_game *game)
{
    if (game->blocks.cobble)
        mlx_destroy_image(game->mlx, game->blocks.cobble);
    if (game->blocks.cobble_t)
        mlx_destroy_image(game->mlx, game->blocks.cobble_t);
    if (game->blocks.grass)
        mlx_destroy_image(game->mlx, game->blocks.grass);
}

int exit_key(int key, t_game *game)
{
    if (key == ESC)
        clean_up(game);
    return (0);
}

void    game_loop(t_game    *game)
{
    mlx_key_hook(game->win, exit_key, game);
    mlx_loop(game->mlx);
}