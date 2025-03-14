#include "so_long.h"

static bool closest(int x, t_game *game)
{
    int diff;
    diff = (game->blocks_x / 2) - x;
    if (diff >= 0)
        return(true);
    return (false);
}

void    player_fill(t_game *game, int x, int y)
{
    mlx_put_image_to_window(game->mlx, game->win, game->blocks.grass, PIXELS * x, PIXELS * y);
    if (closest(x, game))
    {
        game->map[y][x] = 'R';
        mlx_put_image_to_window(game->mlx, game->win, game->blocks.catr, PIXELS * x, PIXELS * y);
    }
    else
    {
        game->map[y][x] = 'L';
        mlx_put_image_to_window(game->mlx, game->win, game->blocks.catl, PIXELS * x, PIXELS * y);
    }
}

void update_blocks(t_game *game, int x, int y)
{
    if (game->map[y][x] == 'P' || game->map[y][x] == 'R' || game->map[y][x] == 'L' || game->map[y][x] == 'U' || game->map[y][x] == 'D')
    {
        if (game->map[y][x] == 'P'  || game->map[y][x] == 'R')
            mlx_put_image_to_window(game->mlx, game->win, game->blocks.catr, PIXELS * x, PIXELS * y);
        else if (game->map[y][x] == 'L')
            mlx_put_image_to_window(game->mlx, game->win, game->blocks.catl, PIXELS * x, PIXELS * y);
    }
    else if (game->map[y][x] == 'C')
        mlx_put_image_to_window(game->mlx, game->win, game->blocks.food, PIXELS * x, PIXELS * y);
    else if (game->map[y][x] == 'E')
        mlx_put_image_to_window(game->mlx, game->win, game->blocks.exit_c, PIXELS * x, PIXELS * y);
    else if (game->map[y][x] == 'O')
        mlx_put_image_to_window(game->mlx, game->win, game->blocks.exit_o, PIXELS * x, PIXELS * y);
    else if(game->map[y][x] != '1')
        mlx_put_image_to_window(game->mlx, game->win, game->blocks.grass, PIXELS * x, PIXELS * y);
    else if(game->map[y][x] == '1' && y + 1 < game->blocks_y && game->map[y + 1][x] == '1')
        mlx_put_image_to_window(game->mlx, game->win, game->blocks.cobble_t, PIXELS * x, PIXELS * y);
    else if (game->map[y][x] == '1')
        mlx_put_image_to_window(game->mlx, game->win, game->blocks.cobble, PIXELS * x, PIXELS * y);
}
void    player_dir(t_game *game)
{
    if (game->player.old_pos_x < game->player.p_x)
    {
        game->map[game->player.p_y][game->player.p_x] = 'R';
        mlx_put_image_to_window(game->mlx, game->win, game->blocks.catr, PIXELS * game->player.p_x, PIXELS * game->player.p_y);
    }
    else if (game->player.old_pos_x > game->player.p_x)
    {
        game->map[game->player.p_y][game->player.p_x] = 'L';
        mlx_put_image_to_window(game->mlx, game->win, game->blocks.catl, PIXELS * game->player.p_x, PIXELS * game->player.p_y);
    }
    else if (game->player.old_pos_y < game->player.p_y)
    {
        game->map[game->player.p_y][game->player.p_x] = 'D';
        mlx_put_image_to_window(game->mlx, game->win, game->blocks.catd, PIXELS * game->player.p_x, PIXELS * game->player.p_y);
    }
    else if (game->player.old_pos_y > game->player.p_y)
    {
        game->map[game->player.p_y][game->player.p_x] = 'U';
        mlx_put_image_to_window(game->mlx, game->win, game->blocks.catu, PIXELS * game->player.p_x, PIXELS * game->player.p_y);
    }
}
