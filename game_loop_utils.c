#include "so_long.h"

void    destroy_images(t_game *game)
{
    if (game->blocks.cobble)
        mlx_destroy_image(game->mlx, game->blocks.cobble);
    if (game->blocks.cobble_t)
        mlx_destroy_image(game->mlx, game->blocks.cobble_t);
    if (game->blocks.grass)
        mlx_destroy_image(game->mlx, game->blocks.grass);
    if (game->blocks.cat)
        mlx_destroy_image(game->mlx, game->blocks.cat);
}

int player_input(int key, t_game *game)
{
    if (key == ESC)
        clean_up(game);
    game->player.old_pos_x = game->player.p_x;
    game->player.old_pos_y = game->player.p_y;
    if (key == RIGHT)
        game->player.p_x++;
    else if (key == LEFT)
        game->player.p_x--;
    else if (key == UP)
        game->player.p_y--;
    else if (key == DOWN)
        game->player.p_y++;
    if (game->map[game->player.p_y][game->player.p_x] != '1')
    {
        game->map[game->player.old_pos_y][game->player.old_pos_x] = '0';
        game->map[game->player.p_y][game->player.p_x] = 'P';
        mlx_put_image_to_window(game->mlx, game->win, game->blocks.grass, PIXELS * game->player.old_pos_x, PIXELS * game->player.old_pos_y);
        mlx_put_image_to_window(game->mlx, game->win, game->blocks.cat, PIXELS * game->player.p_x, PIXELS * game->player.p_y);
    }
    else
    {
        game->player.p_x = game->player.old_pos_x;
        game->player.p_y = game->player.old_pos_y;
    }
    print_grid(game->map);puts("");
    return (0);
}

void    game_loop(t_game    *game)
{
    mlx_do_key_autorepeaton(game->mlx);
    mlx_key_hook(game->win, player_input, game);
    mlx_loop(game->mlx);
}