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

# define oussmalloc(...) NULL // for malloc failure testing.

// constant return
# define VALID_SYMBOL 0
# define INVALID_S -1

# include <fcntl.h>  // for open and close.
# include <stdlib.h> // for malloc, size_t
# include <unistd.h> // for write
# include <stdbool.h> // for boolean checks
# include <math.h> // for randomizing blocks
# include "minilibx-linux/mlx.h"

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
int     primary_parse(char *map_name, t_parse *parse);
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
void    game_loop(char *map_name, t_parse *parse, int *fd);
char    **create_2d_grid(int fd, t_parse *parse);
void    free_grid(char **grid);

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