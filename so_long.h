#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>  // for open and close.
# include <stdlib.h> // for malloc, size_t
#include <unistd.h>




//printing errors
void    usage_error(void);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

// GNL functions
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1337
# endif

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *s);
char	*ft_strdup(char *s1);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strchr(const char *s, int c);

// for testing.
#include <stdio.h>

#endif //SO_LONG_H