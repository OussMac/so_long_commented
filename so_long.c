/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oimzilen <oimzilen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 01:12:20 by oimzilen          #+#    #+#             */
/*   Updated: 2025/03/14 01:12:29 by oimzilen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
