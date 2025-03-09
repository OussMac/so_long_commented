#include "so_long.h"




int main(int argc, char *av[])
{
	t_parse	parse;
	int		fd;
	if (argc != 2)
		return (usage_error(), EXIT_FAILURE);
	if(ft_strncmp(ft_strrchr(av[1], '.'), ".ber", 4) != 0)
		return (usage_error(),EXIT_FAILURE);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (ft_putstr_fd("Failed to open file.\n", 2), EXIT_FAILURE);
	get_max_x_y(fd, &parse);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (ft_putstr_fd("Failed to open file.\n", 2), EXIT_FAILURE);
	if (process_map(fd, &parse) == -1)
		return (close(fd), ft_putstr_fd("Invalid Map.\n", 2), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
