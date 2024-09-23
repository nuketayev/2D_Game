/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anuketay <anuketay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 18:22:11 by anuketay          #+#    #+#             */
/*   Updated: 2024/09/23 19:09:41 by anuketay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	initialize_game_state(t_game_state *game)
{
	game->player_pos_x = 0;
	game->player_pos_y = 0;
	game->exit = 0;
	game->player = 0;
	game->row = 0;
	game->col = 0;
	game->is_game_over = 0;
	game->move_count = 1;
	game->map = NULL;
}

void	validate_args(t_game_state *game, int argc, char **argv)
{
	if (argc != 2)
		abort_game("\nError\nUsage: './so_long ./maps/[map name]'\n", game);
	if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".ber", 4))
	{
		ft_putendl_fd("\nError", 1);
		abort_game("Map file should be .ber type, cabron...\n", game);
	}
}

void	load_game_map(t_game_state *game, int fd)
{
	int		i;
	char	*line;
	int		rows;

	i = 0;
	rows = game->row + 1;
	game->map = (char **)malloc(sizeof(char *) * rows);
	if (!game->map)
		abort_game("Error\n Malloc error 01", game);
	while (i < rows)
	{
		line = get_next_line(fd);
		game->map[i] = ft_strtrim(line, "\n");
		i++;
		free(line);
	}
}

int	main(int argc, char **argv)
{
	t_game_state	game;
	int				fd;
	int				fd_x;
	int				fd_y;

	initialize_game_state(&game);
	validate_args(&game, argc, argv);
	fd_x = open(argv[1], O_RDONLY);
	fd_y = open(argv[1], O_RDONLY);
	game.collectibles = count_collectibles(&game);
	game.row = row_count(fd_x);
	game.col = col_count(fd_y);
	fd = open(argv[1], O_RDONLY);
	load_game_map(&game, fd);
	check_map(&game);
	close(fd_x);
	close(fd_y);
	close(fd);
	start_game(&game);
}
