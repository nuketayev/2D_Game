#include "so_long.h"

void	checkMap(gameState *game, int fd_map)
{
	ft_putendl_fd("\nChecking the map...\n", 1);
	validate_elements(game);
	shape_check(game);
	ft_putendl_fd("\nMap is checked. Valid.\n", 1);
}

int colCount(int fdY)
{
    char	*ln;
    int		cols;

    while (1)
    {
        ln = get_next_line(fdY);
        if (fdY < 0)
        {
            ft_putendl_fd("Error", 1);
            ft_putendl_fd("\nThe map is not found!", 1);
        }
        if (!ln)
            break ;
        cols = ft_strlen(ln) - 1;
        free(ln);
    }
    return (cols);
}

int rowCount(int fdX)
{
    char	*ln;
    int		rows;

    rows = 0;
    while (1)
    {
        ln = get_next_line(fdX);
        if (!ln)
            break ;
        rows++;
        free(ln);
    }
    if (rows == 0)
    {
        ft_putendl_fd("Error", 1);
        ft_putendl_fd("\nThe map is not found!", 1);
        exit(0);
    }
    return (rows);
}