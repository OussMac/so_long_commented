#include "so_long.h"

int	main(int argc, char *av[])
{
	t_parse	parse;
	int		fd;

	input_check(argc, av);
	ft_bzero(&parse, sizeof(t_parse));
	printf(" ===> %d\n", parse.x_max);
	printf(" ===> %d\n", parse.y_max);
	fd = primary_parse(av[1], &parse);
	process_map(fd, &parse);
	return (close(fd), EXIT_SUCCESS);
}
