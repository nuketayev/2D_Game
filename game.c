/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anuketay <anuketay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 18:22:23 by anuketay          #+#    #+#             */
/*   Updated: 2024/09/23 19:07:39 by anuketay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	start_game(t_game_state *game)
{
	ft_putendl_fd("\nInitializing the game...\n", 1);
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->col * WIDTH, game->row * HEIGHT,
			"so_long");
	load_textures(game);
	render_map(game);
	mlx_key_hook(game->win, controls, game);
	mlx_hook(game->win, 17, 0, close_game_window, game);
	mlx_expose_hook(game->win, render_map, game);
	mlx_loop(game->mlx);
}

static int	is_valid_move(t_game_state *game, int col, int row, int pressed_key)
{
	game->temp = '0';
	if (game->map[row][col] == '1')
		return (-1);
	if (game->map[row][col] == 'C')
		game->collectibles--;
	if (game->map[row][col] == 'E' && game->collectibles > 0)
	{
		game->temp = 'O';
		write(1, "\nYou need to collect all the money to fly away!\n\n", 49);
		return (1);
	}
	if (game->map[row][col] == 'E' && game->collectibles == 0)
	{
		return (2);
	}
	if (pressed_key != W && pressed_key != S && pressed_key != A
		&& pressed_key != D && pressed_key != KEY_ARROW_UP
		&& pressed_key != KEY_ARROW_DOWN && pressed_key != KEY_ARROW_LEFT
		&& pressed_key != KEY_ARROW_RIGHT)
		return (-1);
	else
		return (1);
}

void	end_game(t_game_state *game, int col, int row)
{
	game->map[row][col] = 'F';
	render_map(game);
	game->is_game_over = 1;
	ft_putendl_fd("\nCongratulation! You've collected all the $$$", 1);
	ft_putendl_fd("Welcome to Medellin Cartel Amigo!", 1);
	ft_putendl_fd("\n\033[1mTo fly away press any key!\033[0m\n", 1);
}

static void	move_player(t_game_state *game, int target_col, int target_row,
		int pressedKey)
{
	int	is_valid;
	int	prev_col;
	int	prev_row;

	prev_col = game->player_pos_y;
	prev_row = game->player_pos_x;
	(void)pressedKey;
	is_valid = is_valid_move(game, target_col, target_row, pressedKey);
	if (is_valid != -1)
	{
		game->player_pos_y = target_col;
		game->player_pos_x = target_row;
		if (game->temp != 'O')
			game->map[target_row][target_col] = 'P';
		else
			game->map[target_row][target_col] = 'O';
		if (game->map[prev_row][prev_col] != 'O')
			game->map[prev_row][prev_col] = '0';
		else
			game->map[prev_row][prev_col] = 'E';
		print_move_counter(game->move_count++);
		render_map(game);
	}
	if (is_valid == 2)
		end_game(game, target_col, target_row);
}

int	controls(int keycode, t_game_state *game)
{
	int	target_col;
	int	target_row;

	target_col = game->player_pos_y;
	target_row = game->player_pos_x;
	if (keycode == A || keycode == KEY_ARROW_LEFT)
		target_col--;
	else if (keycode == W || keycode == KEY_ARROW_UP)
		target_row--;
	else if (keycode == S || keycode == KEY_ARROW_DOWN)
		target_row++;
	else if (keycode == D || keycode == KEY_ARROW_RIGHT)
		target_col++;
	else if (keycode == ESC)
		close_game_window(game);
	if (game->is_game_over != 1)
		move_player(game, target_col, target_row, keycode);
	else if (game->is_game_over == 1)
		close_game_window(game);
	return (0);
}
