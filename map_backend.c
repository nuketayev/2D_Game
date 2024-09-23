/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_backend.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anuketay <anuketay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 18:22:32 by anuketay          #+#    #+#             */
/*   Updated: 2024/09/23 19:07:00 by anuketay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	col_count(int fdY)
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

int	row_count(int fdX)
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

int	count_collectibles(t_game_state *game)
{
	int	col;
	int	row;
	int	collectible_count;

	row = 0;
	collectible_count = 0;
	while (row < game->row)
	{
		col = 0;
		while (col < game->col)
		{
			if (game->map[row][col] == 'C')
			{
				collectible_count++;
			}
			col++;
		}
		row++;
	}
	return (collectible_count);
}
