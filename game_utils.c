#include "so_long.h"

void	freeMap(gameState *game)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
}

void	abortGame(char *message, gameState *game)
{
	ft_putendl_fd(message, 1);
	if (game->map != NULL)
		freeMap(game);
	exit(EXIT_FAILURE);
}

int	closeGameWindow(gameState *game)
{
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_image(game->mlx, game->images.exit);
	if (game->images.collectible)
		mlx_destroy_image(game->mlx, game->images.collectible);
	if (game->images.player)
		mlx_destroy_image(game->mlx, game->images.player);
	if (game->images.floor)
		mlx_destroy_image(game->mlx, game->images.floor);
	if (game->images.wall)
		mlx_destroy_image(game->mlx, game->images.wall);
	if (game->images.closed_exit)
		mlx_destroy_image(game->mlx, game->images.closed_exit);
	if (game->images.open_exit)
		mlx_destroy_image(game->mlx, game->images.open_exit);
	freeMap(game);
	free(game->mlx);
	exit(0);
}

void	printMoveCounter(int moveCount)
{
	write(1, "Movement counter: ", 18);
	ft_putnbr_fd(moveCount, 1);
	if (moveCount == 1)
		write(1, " move\n", 7);
	else
		write(1, " moves\n", 7);
	if (moveCount == 20)
	{
		ft_putendl_fd("\nYou've made 20 moves! You're a slowpoke!", 1);
		ft_putendl_fd("To give up press ESC key!\n", 1);
	}
	if (moveCount == 80)
	{
		ft_putendl_fd("\nYou've made 85 moves! You're a snail!", 1);
		ft_putendl_fd("To give up press ESC key!\n", 1);
	}
}