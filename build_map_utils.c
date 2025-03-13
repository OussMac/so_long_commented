#include "so_long.h"

static void print_moves(void)
{
    static int moves = 1;

    ft_putstr_fd("[+] Moves ==> ", STDOUT_FILENO);
    ft_putnbr_fd(moves++, STDOUT_FILENO);
    ft_putstr_fd(".\n", STDOUT_FILENO);
}

static bool closest(int x, t_game *game)
{
    int diff;
    diff = (game->blocks_x / 2) - x;
    if (diff >= 0)
        return(true);
    return (false);
}

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
            if(game->map[y][x] != '1')
                mlx_put_image_to_window(game->mlx, game->win, game->blocks.grass, PIXELS * x, PIXELS * y);
            else if(game->map[y][x] == '1' && y + 1 < game->blocks_y && game->map[y + 1][x] == '1')
                mlx_put_image_to_window(game->mlx, game->win, game->blocks.cobble_t, PIXELS * x, PIXELS * y);
            else if (game->map[y][x] == '1')
                mlx_put_image_to_window(game->mlx, game->win, game->blocks.cobble, PIXELS * x, PIXELS * y);
            if (game->map[y][x] == 'P')
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
            x++;
        }
        y++;
    }
}

void    update_map(t_game *game)
{
    int y;
    int x;

    y = 0;
    if (game->food <= 0)
        {
            clean_up(game);
            exit (EXIT_SUCCESS);
        }
    while (y < game->blocks_y)
    {
        x = 0;
        while(x < game->blocks_x)
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
            else if(game->map[y][x] != '1')
                mlx_put_image_to_window(game->mlx, game->win, game->blocks.grass, PIXELS * x, PIXELS * y);
            else if(game->map[y][x] == '1' && y + 1 < game->blocks_y && game->map[y + 1][x] == '1')
                mlx_put_image_to_window(game->mlx, game->win, game->blocks.cobble_t, PIXELS * x, PIXELS * y);
            else if (game->map[y][x] == '1')
                mlx_put_image_to_window(game->mlx, game->win, game->blocks.cobble, PIXELS * x, PIXELS * y);
            x++;
        }
        y++;
    }
}

void    update_player(t_game *game, int *flag)
{
    if (game->map[game->player.p_y][game->player.p_x] != '1' && *flag != 0)
    {
        if (game->map[game->player.p_y][game->player.p_x] == 'C')
        {
            game->food--;
            ft_putstr_fd("[-] Eaten +1 Food!!!\n", 1);
        }
        game->map[game->player.old_pos_y][game->player.old_pos_x] = '0';
        game->map[game->player.p_y][game->player.p_x] = 'P';
        mlx_put_image_to_window(game->mlx, game->win, game->blocks.grass, PIXELS * game->player.old_pos_x, PIXELS * game->player.old_pos_y);
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
        print_moves();
    }
    else
    {
        *flag = 1;
        game->player.p_x = game->player.old_pos_x;
        game->player.p_y = game->player.old_pos_y;
    }
}
