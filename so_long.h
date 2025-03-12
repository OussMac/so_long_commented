#ifndef SO_LONG_H
# define SO_LONG_H


// constants for errors
# define USAGE 1
# define INVALID 2
# define OP_FAIL 3
# define EMPTY 4
# define MAP_GAP 5
# define SYMBOL 6
# define RECT 7
# define PARAMS 8
# define MALLOC_F 9
# define PATH_BLOCKED 10
# define IMAGE 11

// constants for the game loop
# define PIXELS 96
# define TITLE "ESCAPE MINECRAFT"
# define GRASS "textures/simple.xpm"
# define COBBLE "textures/cobble_block.xpm"
# define COBBLE_T "textures/cobble_block_top.xpm"
# define CATR "textures/cat_right.xpm"
# define CATL "textures/cat_left.xpm"

# define oussmalloc(...) NULL // for malloc failure testing.

// constant return
# define VALID_SYMBOL 0
# define INVALID_S -1

// key codes
# define ESC 65307
# define RIGHT 65363
# define LEFT 65361
# define UP 65362
# define DOWN 65364
// close event
# define CLOSE_EVENT 480622528

# include <fcntl.h>  // for open and close.
# include <stdlib.h> // for malloc, size_t
# include <unistd.h> // for write
# include <stdbool.h> // for boolean checks
# include <math.h> // for randomizing blocks
# include ".mlx_linux/mlx.h"
#include <limits.h>

typedef struct s_blocks
{
    void    *grass;
    void    *cobble;
    void    *cobble_t;
    void    *catr;
    void    *catl;
}   t_blocks;

typedef struct s_player
{
    int p_x;
    int p_y;
    int old_pos_x;
    int old_pos_y;
}   t_player;

typedef struct s_game
{
    int         pxl;
    char        **map;
    t_blocks    blocks;
    t_player    player;
    void        *mlx;
    void        *win;
    int         map_w;
    int         map_h;
    int         blocks_x;
    int         blocks_y;
}   t_game;

typedef struct s_parse
{
    int x;
    int y;
    int x_max;
    int y_max;
    int p_count;
    int c_count;
    int e_count;
    int player_x;
    int player_y;
    int found_c;
    int found_e;
}   t_parse;

// struct for the floodfill algorithm.
typedef struct s_pos
{
    int x;
    int y;
}   t_pos;


// processing map
void	input_check(int argc, char **av);
void    primary_parse(char *map_name, t_parse *parse, int fd);
void    process_map(int fd, t_parse *parse);
bool    cmp_symbol(char c);
void	ft_bzero(void *s, size_t n);
void    count_params(char symbol, t_parse *parse);
void    width_check(char *row, int fd, t_parse *parse);
void    params_check(t_parse *parse);
char    *cut_row(char *row_uncut);

// flood fill path parsing
void    parse_path(char *map_name, t_parse *parse);

//for testing.
void    print_grid(char **grid);

// game loop
void    load_game(char *map_name, t_parse *parse, int fd);
char    **create_2d_grid(int fd, t_parse *parse);
void    fill_map(t_game *game);
void    game_loop(t_game    *game);
void    update_map(t_game *game);
void    update_player(t_game *game, int *flag);
void    free_grid(char **grid);
void    destroy_images(t_game *game);
void    clean_up(t_game *game);

// printing errors
void	print_error(int error);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

// GNL functions
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1337
# endif

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *s);
char	*ft_strdup(char *s1);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strchr(const char *s, int c);

// for testing.
#include <stdio.h>

#endif //SO_LONG_H