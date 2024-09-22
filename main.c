#include "so_long.h"

static	void	initializeGameState(gameState *game)
{
	game->playerPosX = 0;
	game->playerPosY = 0;
	game->exit = 0;
	game->player = 0;
	game->row = 0;
	game->col = 0;
	game->isGameOver = 0;
	game->moveCount = 1;
	game->map = NULL;
}

void	validateArgs(gameState *game, int argc, char **argv)
{
	if (argc != 2)
		abortGame("\nError\nUsage: './so_long ./maps/[map name]'\n", game);
	if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".ber", 4))
	{
		ft_putendl_fd("\nError", 1);
		abortGame("Map file should be .ber type, cabron...\n", game);
	}
}

void	loadGameMap(gameState *game, int fd)
{
    int i;
    char *line;
    int rows;

    i = 0;
    rows = game->row + 1;
    game->map = (char **)malloc(sizeof(char *) * rows);
    if (!game->map)
        abortGame("Error\n Malloc error 01", game);
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
	gameState	game;
	int		fd;
	int		fd_x;
	int		fd_y;
	int		fd_map;

	initializeGameState(&game);
	validateArgs(&game, argc, argv);
	fd_x = open(argv[1], O_RDONLY);
	fd_y = open(argv[1], O_RDONLY);
	fd_map = open(argv[1], O_RDONLY);
	game.collectibles = countCollectibles(&game);
	game.row = rowCount(fd_x);
	game.col = colCount(fd_y);
	fd = open(argv[1], O_RDONLY);
	loadGameMap(&game, fd);
	checkMap(&game, fd_map);
	close(fd_x);
	close(fd_y);
	close(fd);
	close(fd_map);
	startGame(&game);
}
