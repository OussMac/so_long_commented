#include "so_long.h"

int	main(int argc, char *av[])
{
	t_parse	parse;
	int		fd;

	input_check(argc, av);
	fd = primary_parse(av[1], &parse);
	process_map(fd, &parse);
	parse_path(av[1], &parse);
	game_loop(av[1], &parse, &fd);
	return (close(fd), EXIT_SUCCESS);
}
