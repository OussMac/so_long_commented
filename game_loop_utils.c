#include "so_long.h"

void    destroy_images(t_game *game)
{
    if (game->blocks.cobble)
        mlx_destroy_image(game->mlx, game->blocks.cobble);
    if (game->blocks.cobble_t)
        mlx_destroy_image(game->mlx, game->blocks.cobble_t);
    if (game->blocks.grass)
        mlx_destroy_image(game->mlx, game->blocks.grass);
    if (game->blocks.catr)
        mlx_destroy_image(game->mlx, game->blocks.catr);
    if (game->blocks.catl)
        mlx_destroy_image(game->mlx, game->blocks.catl);
}

int player_input(int key, t_game *game)
{
    static int flag = 0;

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
    update_player(game, &flag);
    print_grid(game->map);
    puts("");
    return (0);
}

bool    within_range(int click, int player)
{
    int max_p;
    int min_p;

    max_p = player + 25;
    min_p = player - 25;
    if (click < max_p && click > min_p)
        return (true);
    return (false);
}

int mouse_input(int button,int x, int y, t_game *game)
{
    int cen_x = x;
    int cen_y = y;
    int p_x = game->player.p_x * PIXELS + (PIXELS / 2);
    int p_y = game->player.p_y * PIXELS + (PIXELS / 2);
    if (button == 1)
    {
        if (within_range(cen_x, p_x) && within_range(cen_y, p_y))
        {
            printf("player clicked.\n");
            // mlx_string_put(game->mlx, game->win, p_x - 25, p_y - 48, 0xFFFFFF, "Hey stop that!");
            clean_up(game);
        }
    }
    return (0);
}

int close_window(t_game *game)
{
    clean_up(game);
    return (0);
}

int player_hold(t_game *game)
{
    (void)game;
    return (0);
}

int update_frames(t_game *game)
{
    (void)game;
    update_map(game);
    return (0);
}

void    game_loop(t_game    *game)
{
    mlx_hook(game->win, 2, 1L<<0, player_hold, &game);
    mlx_key_hook(game->win, player_input, game);
    mlx_mouse_hook(game->win, mouse_input, game);
    mlx_hook(game->win, 17, 0, close_window, game);
    mlx_loop_hook(game->mlx, update_frames, game);
    mlx_loop(game->mlx);
}