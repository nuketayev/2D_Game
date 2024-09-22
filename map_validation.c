#include "so_long.h"

void	checkMap(gameState *game, int fd_map)
{
	ft_putendl_fd("\nChecking the map...\n", 1);
	validate_elements(game);
	shape_check(game);
	ft_putendl_fd("\nMap is checked. Valid.\n", 1);
}

void	check_Walls(gameState *game)
{
	int	row;
	int	col;

	row = 0;
	while (game->map[row])
	{
		col = 0;
		while (game->map[row][col])
		{
			if (game->map[0][col] != '1' || game->map[game->row - 1][col] != '1')
				abortGame("Error\nThe map must be surrounded by walls", game);
			if (game->map[row][0] != '1' || game->map[row][game->col - 1] != '1')
				abortGame("Error\nThe map must be surrounded by walls", game);
			col++;
		}
		row++;
	}
}

void	elements_counter(gameState *game, char c, int row, int col)
{
	if (c == 'C')
		game->collectibles++;
	else if (c == 'E')
		game->exit++;
	else if (c == 'P')
	{
		game->player++;
		game->playerPosX = row;
		game->playerPosY = col;
	}
	else if (c == '0' || c == '1')
		return ;
	else
	{
		write(1, "\nError\n", 8);
		abortGame("Unknown element in the map", game);		
	}
		
}

void	shape_check(gameState *game)
{
	int	col;
	int	row;
	int	size;

	col = 0;
	row = 0;
	size = ft_strlen(game->map[0]);
	while (game->map[row] != 0)
	{
		col = ft_strlen(game->map[row]);
		if (col != size)
			abortGame("Error\nMap must be rectangular", game);
		row++;
	}
	check_Walls(game);
}

void	validate_elements(gameState *game)
{
	int	row;
	int	col;

	row = 0;
	while (game->map[row])
	{
		col = 0;
		while (game->map[row][col])
		{
			elements_counter(game, game->map[row][col], row, col);
			col++;
		}
		row++;
	}
	if (game->player == 0)
		abortGame("Error\nOne starting position is required.\n", game);
	else if (game->player > 1)
		abortGame("Error\nThere can't be multiple starting positions.\n", game);
	else if (game->exit == 0)
		abortGame("Error\nThe map must have at least one exit.\n", game);
	else if (game->collectibles == 0)
		abortGame("Error\nThe map must have at least one collectible.\n", game);
}
