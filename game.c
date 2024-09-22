#include "so_long.h"

void	startGame(gameState *game)
{
	ft_putendl_fd("\nInitializing the game...\n", 1);
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->col * WIDTH,
			game->row * HEIGHT, "so_long");
	loadTextures(game);
	renderMap(game);
	mlx_key_hook(game->win, controls, game);
	mlx_hook(game->win, 17, 0, closeGameWindow, game);
	mlx_expose_hook(game->win, renderMap, game);
	mlx_loop(game->mlx);
}

static int	isValidMove(gameState *game, int col, int row, int pressed_key)
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

void	endGame(gameState *game, int col, int row)
{
	game->map[row][col] = 'F';
	renderMap(game);
	game->isGameOver = 1;
    ft_putendl_fd("\nCongratulation! You've collected all the $$$", 1);
    ft_putendl_fd("Welcome to Medellin Cartel Amigo!", 1);
    ft_putendl_fd("\n\033[1mTo fly away press any key!\033[0m\n", 1);
}

static void	movePlayer(gameState *game, int targetCol, int targetRow, int pressedKey)
{
    int	isValid;
    int	prevCol;
    int	prevRow;

    prevCol = game->playerPosY;
    prevRow = game->playerPosX;
    (void)pressedKey;
    isValid = isValidMove(game, targetCol, targetRow, pressedKey);
    if (isValid != -1)
    {
        game->playerPosY = targetCol;
        game->playerPosX = targetRow;
        if (game->temp != 'O')
            game->map[targetRow][targetCol] = 'P';
        else
            game->map[targetRow][targetCol] = 'O';
        if (game->map[prevRow][prevCol] != 'O')
            game->map[prevRow][prevCol] = '0';
        else
            game->map[prevRow][prevCol] = 'E';
        printMoveCounter(game->moveCount++);
        renderMap(game);
    }
    if (isValid == 2)
        endGame(game, targetCol, targetRow);
}

int	controls(int keycode, gameState *game)
{
    int targetCol;
    int targetRow;

    targetCol = game->playerPosY;
    targetRow = game->playerPosX;
    if (keycode == A || keycode == KEY_ARROW_LEFT)
        targetCol--;
    else if (keycode == W || keycode == KEY_ARROW_UP)
        targetRow--;
    else if (keycode == S || keycode == KEY_ARROW_DOWN)
        targetRow++;
    else if (keycode == D || keycode == KEY_ARROW_RIGHT)
        targetCol++;
    else if (keycode == ESC)
        closeGameWindow(game);
    if (game->isGameOver != 1)
        movePlayer(game, targetCol, targetRow, keycode);
    else if (game->isGameOver == 1)
        closeGameWindow(game);
    return (0);
}
