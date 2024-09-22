#ifndef SO_LONG_H
#define SO_LONG_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <fcntl.h>
#include "./minilibx-linux/mlx.h"
#include "./libft/libft.h"

#define WIDTH 128
#define HEIGHT 128
#define W 119
#define A 97
#define S 115
#define D 100
#define KEY_ARROW_UP 65362
#define KEY_ARROW_LEFT 65361
#define KEY_ARROW_DOWN 65364
#define KEY_ARROW_RIGHT 65363
#define ESC 65307

/*game elements*/
#define PLAYER "./elements/player.xpm"
#define WALL "./elements/wall.xpm"
#define COLLECTIBLE "./elements/collectible.xpm"
#define EXIT "./elements/exit.xpm"
#define FLOOR "./elements/floor.xpm"
#define CLOSED_DOOR "./elements/closed_door.xpm"
#define OPEN_DOOR "./elements/open_door.xpm"

typedef struct s_assets
{
	void	*collectible;
	void	*player;
	void	*space;
	void	*wall;
	void	*exit;
	void	*open_exit;
	void	*closed_exit;
}	ImageAssets;

typedef struct s_game
{
	ImageAssets	images;
	void	*mlx;
	void	*win;
	char	**map;
	char	temp;
	int		row;
	int		col;
	int		exit;
	int		collectibles;
	int		player;
	int		playerPosY;
	int		playerPosX;
	int		isGameOver;
	int		moveCount;
}	gameState;

void	abortGame(char *a, gameState *game);
int		countCollectibles(gameState *game);
int		rowCount(int fd_x);
int		colCount(int fd_y);
void	checkMap(gameState *game, int fd_map);
void	startGame(gameState *game);
void	validate_elements(gameState *game);
void	shape_check(gameState *game);

void	loadTextures(gameState *game);
int		renderMap(gameState *game);
int		controls(int keycode, gameState *game);

int		closeGameWindow(gameState *game);
void	printMoveCounter(int n);

#endif