#include "so_long.h"

char    *cut_row(char *row_uncut)
{
    int     len;
    char    *temp;
    char    *new_row;

    printf("==> %s\n", row_uncut);
    len = ft_strlen(row_uncut);
    temp = row_uncut;
    if (ft_strchr(row_uncut, '\n'))
        new_row = ft_substr(row_uncut, 0, len - 1);
    else
        new_row = ft_strdup(row_uncut);
    free(temp);
    return (new_row);
}

int process_row(char *row_uncut, int *ptr_x, int *ptr_y, t_parse *parse)
{
    int     i;
    char    *row;

    i = 0;
    if (!row_uncut)
        return (0);
    row = cut_row(row_uncut);
    while (row[i])
    {
        if ((*ptr_y == 0  || *ptr_y == parse->y_max - 2) && row[i] != '1')
            return (-1);
        if ((*ptr_x == 0  || *ptr_x == parse->x_max - 1) && row[i] != '1')
            return (-1);
        i++;
        (*ptr_x)++;
    }
    return (0);
}

int     process_map(int fd, t_parse *parse)
{
    char    *row;
    int     x;
    int     y;

    y = 0;
    printf("===> %d\n", parse->x_max);
    printf("===> %d\n", parse->y_max);
    row = get_next_line(fd);
    if (process_row(row, &x, &y, parse) == -1)
        return (-1);
    while (row)
    {
        x = 0;
        row = get_next_line(fd);
        if (process_row(row, &x, &y, parse) == -1)
            return (-1);
        y++;
    }
    return (0);
}

void    get_max_x_y(int fd, t_parse *parse)
{
    int     i;
    char    *row;

    i = 0;
    parse->x_max = 0;
    parse->y_max = 0;
    row = get_next_line(fd);
    while (row[i])
    {
        parse->x_max++;
        i++;
    }
    while (row)
    {
        free(row);
        row = get_next_line(fd);
        parse->y_max++;
    }
    close(fd);
}