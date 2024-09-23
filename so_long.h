/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anuketay <anuketay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 19:01:44 by anuketay          #+#    #+#             */
/*   Updated: 2024/09/23 19:06:55 by anuketay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./libft/libft.h"
# include "./minilibx-linux/mlx.h"
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define WIDTH 128
# define HEIGHT 128
# define W 119
# define A 97
# define S 115
# define D 100
# define KEY_ARROW_UP 65362
# define KEY_ARROW_LEFT 65361
# define KEY_ARROW_DOWN 65364
# define KEY_ARROW_RIGHT 65363
# define ESC 65307

/*game elements*/
# define PLAYER "./elements/player.xpm"
# define WALL "./elements/wall.xpm"
# define COLLECTIBLE "./elements/collectible.xpm"
# define EXIT "./elements/exit.xpm"
# define FLOOR "./elements/floor.xpm"
# define CLOSED_DOOR "./elements/closed_door.xpm"
# define OPEN_DOOR "./elements/open_door.xpm"

typedef struct s_assets
{
	void			*collectible;
	void			*player;
	void			*floor;
	void			*wall;
	void			*exit;
	void			*open_exit;
	void			*closed_exit;
}					t_image_assets;

typedef struct s_game
{
	t_image_assets	images;
	void			*mlx;
	void			*win;
	char			**map;
	char			temp;
	int				row;
	int				col;
	int				exit;
	int				collectibles;
	int				player;
	int				player_pos_y;
	int				player_pos_x;
	int				is_game_over;
	int				move_count;
}					t_game_state;

void				abort_game(char *a, t_game_state *game);
int					count_collectibles(t_game_state *game);
int					row_count(int fd_x);
int					col_count(int fd_y);
void				check_map(t_game_state *game);
void				start_game(t_game_state *game);
void				validate_elements(t_game_state *game);
void				shape_check(t_game_state *game);

void				load_textures(t_game_state *game);
int					render_map(t_game_state *game);
int					controls(int keycode, t_game_state *game);

int					close_game_window(t_game_state *game);
void				print_move_counter(int n);

#endif