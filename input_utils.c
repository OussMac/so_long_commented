#include "so_long.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	a;
	char	*ptr;

	i = 0;
	ptr = NULL;
	a = (char ) c;
	while (s[i])
	{
		if (s[i] == a)
			ptr = (char *) s + i;
		i++;
	}
	if (s[i] == a)
		ptr = ((char *) s + i);
	return (ptr);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (!s1 || !s2)
		return (1);
	while (i < n && s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	if (i < n)
		return (s1[i] - s2[i]);
	return (s1[i] - s2[i]);
}

void	input_check(int argc, char **av)
{
	if (argc != 2)
	{
		print_error(USAGE);
		exit(EXIT_FAILURE);
	}
	if(ft_strncmp(ft_strrchr(av[1], '.'), ".ber", 4) != 0)
	{
		print_error(USAGE);
		exit(EXIT_FAILURE);
	}
}