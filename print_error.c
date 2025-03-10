#include "so_long.h"

void	print_error(int error)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	if (error == USAGE)
		ft_putstr_fd("Usage: ./so_long <map_name>.ber\n", STDERR_FILENO);
	else if (error == INVALID)
		ft_putstr_fd("Invalid Map.\n", STDERR_FILENO);
	else if (error == OP_FAIL)
		ft_putstr_fd("Failed To Open File.\n", STDERR_FILENO);
	else if (error == EMPTY)
		ft_putstr_fd("Empty Map.\n", STDERR_FILENO);
	else if (error == MAP_GAP)
		ft_putstr_fd("Found A Gap In The Map.\n", STDERR_FILENO);
	else if (error == SYMBOL)
		ft_putstr_fd("Please Enter A Valid Map Configuration.\n", STDERR_FILENO);
	else if (error == RECT)
		ft_putstr_fd("The Map Must Be Rectangular.", STDERR_FILENO);
	else if (error == PARAMS)
		ft_putstr_fd("Please Enter Exactly 1 Player.\n1 Exit.\nAt least 1 Coin\n", STDERR_FILENO);
	else if (error == MALLOC_F)
		ft_putstr_fd("Malloc Failure.", STDERR_FILENO);
}
