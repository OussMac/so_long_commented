#include "so_long.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

    i = 0;
	if (n == 0)
		return ;
	ptr = (unsigned char *) s;
	while (i < n)
	{
		ptr[i] = 0;
		i++;
	}
}

bool    cmp_symbol(char c)
{
    int     i;
    char    *symbols;

    symbols = "01CEP";
    i = 0;
    while (symbols[i])
    {
        if (c == symbols[i])
            return (true);
        i++;
    }
    return (false);
}

void    count_params(char symbol, t_parse *parse)
{
    if (symbol == 'P')
    {
        parse->player_x = parse->x;
        parse->player_y = parse->y;
        parse->p_count++;
    }
    else if (symbol == 'C')
        parse->c_count++;
    else if (symbol == 'E')
        parse->e_count++;
}

void    width_check(char *row, int fd, t_parse *parse)
{
    int len;

    len = ft_strlen(row);
    if (len != parse->x_max)
    {
        print_error(RECT);
        free(row);
        get_next_line(INVALID_S);
        close(fd);
        exit(EXIT_FAILURE);
    }
}

void    params_check(t_parse *parse)
{
    bool    error;

    error = false;
    if (parse->e_count != 1)
        error = true;
    if (parse->p_count != 1)
        error = true;
    if (parse->c_count < 1)
        error = true;
    if (error)
    {
        print_error(PARAMS);
        exit(EXIT_FAILURE);
    }
}