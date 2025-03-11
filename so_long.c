#include "so_long.h"

int	main(int argc, char *av[])
{
	t_parse	parse;
	int		fd;

	fd = 3;
	input_check(argc, av);
	primary_parse(av[1], &parse, fd);
	process_map(fd, &parse);
	parse_path(av[1], &parse);
	load_game(av[1], &parse, fd);
	return (EXIT_SUCCESS);
}
