#include "so_long.h"




int main(int argc, char *av[])
{
	if (argc != 2)
		return (usage_error(), EXIT_FAILURE);
	if(ft_strncmp(ft_strrchr(av[1], '.'), ".ber", 4) != 0)
		return (usage_error(),EXIT_FAILURE);
	return (EXIT_SUCCESS);
}