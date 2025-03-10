#include "so_long.h"

int	main(int argc, char *av[])
{
	t_parse	parse;
	int		fd;

	input_check(argc, av);
	ft_bzero(&parse, sizeof(t_parse));
	fd = primary_parse(av[1], &parse);
	process_map(fd, &parse);
	printf(" x ===> %d\n y ===> %d\n", parse.player_x, parse.player_y);
	fd = parse_path(av[1], &parse);
	return (close(fd), EXIT_SUCCESS);
}
