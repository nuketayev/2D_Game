#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include "get_next_line.h"

int		ft_strlen(const char *str);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
char	*ft_strchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_putnbr_fd(int n, int fd);
void	ft_putchar_fd(char c, int fd);
char	*ft_strtrim(char const *s1, char const *set);
void	ft_putendl_fd(char *s, int fd);

#endif
