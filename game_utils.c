/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anuketay <anuketay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 18:22:28 by anuketay          #+#    #+#             */
/*   Updated: 2024/09/23 19:07:46 by anuketay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_game_state *game)
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

void	abort_game(char *message, t_game_state *game)
{
	ft_putendl_fd(message, 1);
	if (game->map != NULL)
		free_map(game);
	exit(EXIT_FAILURE);
}

int	close_game_window(t_game_state *game)
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
	free_map(game);
	free(game->mlx);
	exit(0);
}

void	print_move_counter(int move_count)
{
	write(1, "Movement counter: ", 18);
	ft_putnbr_fd(move_count, 1);
	if (move_count == 1)
		write(1, " move\n", 7);
	else
		write(1, " moves\n", 7);
	if (move_count == 20)
	{
		ft_putendl_fd("\nYou've made 20 moves! You're a slowpoke!", 1);
		ft_putendl_fd("To give up press ESC key!\n", 1);
	}
	if (move_count == 80)
	{
		ft_putendl_fd("\nYou've made 85 moves! You're a snail!", 1);
		ft_putendl_fd("To give up press ESC key!\n", 1);
	}
}
