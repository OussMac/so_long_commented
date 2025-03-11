#include "so_long.h"

void    fill_map(t_game *game)
{
    int y;
    int x;

    y = 0;
    while (y < game->blocks_y)
    {
        x = 0;
        while(x < game->blocks_x)
        {
            if(game->map[y][x] == '1' && y + 1 < game->blocks_y && game->map[y + 1][x] == '1')
                mlx_put_image_to_window(game->mlx, game->win, game->blocks.cobble_t, PIXELS * x, PIXELS * y);
            else if (game->map[y][x] == '1')
                mlx_put_image_to_window(game->mlx, game->win, game->blocks.cobble, PIXELS * x, PIXELS * y);
            else if(game->map[y][x] == '0')
                mlx_put_image_to_window(game->mlx, game->win, game->blocks.grass, PIXELS * x, PIXELS * y);
            x++;
        }
        y++;
    }
}