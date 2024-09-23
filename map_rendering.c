/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_rendering.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anuketay <anuketay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 18:22:36 by anuketay          #+#    #+#             */
/*   Updated: 2024/09/23 19:06:58 by anuketay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_textures(t_game_state *game)
{
	int	tile_width;
	int	tile_height;

	tile_width = WIDTH;
	tile_height = HEIGHT;
	game->images.wall = mlx_xpm_file_to_image(game->mlx, WALL, &tile_width,
			&tile_height);
	game->images.player = mlx_xpm_file_to_image(game->mlx, PLAYER, &tile_width,
			&tile_height);
	game->images.floor = mlx_xpm_file_to_image(game->mlx, FLOOR, &tile_width,
			&tile_height);
	game->images.exit = mlx_xpm_file_to_image(game->mlx, EXIT, &tile_width,
			&tile_height);
	game->images.collectible = mlx_xpm_file_to_image(game->mlx, COLLECTIBLE,
			&tile_width, &tile_height);
	game->images.closed_exit = mlx_xpm_file_to_image(game->mlx, CLOSED_DOOR,
			&tile_width, &tile_height);
	game->images.open_exit = mlx_xpm_file_to_image(game->mlx, OPEN_DOOR,
			&tile_width, &tile_height);
}

void	render_map_tile(int col, int row, char tileType, t_game_state *game)
{
	static int	tile_width = WIDTH;
	static int	tile_height = HEIGHT;

	if (tileType == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->images.wall, col
			* tile_width, row * tile_height);
	if (tileType == '0')
		mlx_put_image_to_window(game->mlx, game->win, game->images.floor, col
			* tile_width, row * tile_height);
	if (tileType == 'P')
		mlx_put_image_to_window(game->mlx, game->win, game->images.player, col
			* tile_width, row * tile_height);
	if (tileType == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->images.exit, col
			* tile_width, row * tile_height);
	if (tileType == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->images.collectible,
			col * tile_width, row * tile_height);
	if (tileType == 'O')
		mlx_put_image_to_window(game->mlx, game->win, game->images.closed_exit,
			col * tile_width, row * tile_height);
	if (tileType == 'F')
		mlx_put_image_to_window(game->mlx, game->win, game->images.open_exit,
			col * tile_width, row * tile_height);
}

int	render_map(t_game_state *game)
{
	int	row;
	int	col;

	row = 0;
	while (row < game->row)
	{
		col = 0;
		while (col < game->col)
		{
			render_map_tile(col, row, game->map[row][col], game);
			col++;
		}
		row++;
	}
	return (0);
}
