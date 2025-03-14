#include "so_long.h"

static void print_moves(t_game *game)
{
    static int moves = 1;

    game->moves = moves;
    ft_putstr_fd("[+] Moves ==> ", STDOUT_FILENO);
    ft_putnbr_fd(moves++, STDOUT_FILENO);
    ft_putstr_fd(".\n", STDOUT_FILENO);
}

static bool wall(t_game *game)
{
    if (game->map[game->player.p_y][game->player.p_x] != '1' 
        && game->map[game->player.p_y][game->player.p_x] != 'E')
        return (true);
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
                player_fill(game, x, y);
            x++;
        }
        y++;
    }
}

void    update_map(t_game *game)
{
    char *mvs;
    int y;
    int x;

    mvs = ft_itoa(game->moves);
    y = 0;
    if (game->food <= 0)
        game->map[game->door_y][game->door_x] = 'O';
    while (y < game->blocks_y)
    {
        x = 0;
        while(x < game->blocks_x)
        {
            update_blocks(game, x, y);
            mlx_set_font(game->mlx, game->win, "-sony-fixed-medium-r-normal--24-230-75-75-c-120-iso8859-1");
            mlx_string_put(game->mlx, game->win, 1.2 * PIXELS, 0.56 * PIXELS, 0xFFFFFF, "[+] ==> Moves :");
            mlx_string_put(game->mlx, game->win, 3.1 * PIXELS, 0.56 * PIXELS, 0xFFFFFF, mvs);
            x++;
        }
        y++;
    }
}

void    update_player(t_game *game, int *flag)
{
    if (wall(game) && *flag != 0)
    {
        if (game->map[game->player.p_y][game->player.p_x] == 'C')
            game->food--;
        else if (game->map[game->player.p_y][game->player.p_x] == 'O')
        {
            ft_putstr_fd("You Won!\n", STDOUT_FILENO);
            clean_up(game);
        }
        game->map[game->player.old_pos_y][game->player.old_pos_x] = '0';
        game->map[game->player.p_y][game->player.p_x] = 'P';
        mlx_put_image_to_window(game->mlx, game->win, game->blocks.grass, PIXELS * game->player.old_pos_x, PIXELS * game->player.old_pos_y);
        player_dir(game);
        print_moves(game);
    }
    else
    {
        *flag = 1;
        game->player.p_x = game->player.old_pos_x;
        game->player.p_y = game->player.old_pos_y;
    }
}
