#include "so_long.h"

void loadTextures(gameState *game)
{
    int tileWidth;
    int tileHeight;

    tileWidth = WIDTH;
    tileHeight = HEIGHT;
    game->images.wall = mlx_xpm_file_to_image(game->mlx,
            WALL, &tileWidth, &tileHeight);
    game->images.player = mlx_xpm_file_to_image(game->mlx,
            PLAYER, &tileWidth, &tileHeight);
    game->images.floor = mlx_xpm_file_to_image(game->mlx,
            FLOOR, &tileWidth, &tileHeight);
    game->images.exit = mlx_xpm_file_to_image(game->mlx,
            EXIT, &tileWidth, &tileHeight);
    game->images.collectible = mlx_xpm_file_to_image(game->mlx,
            COLLECTIBLE, &tileWidth, &tileHeight);
    game->images.closed_exit = mlx_xpm_file_to_image(game->mlx,
            CLOSED_DOOR, &tileWidth, &tileHeight);
    game->images.open_exit = mlx_xpm_file_to_image(game->mlx,
            OPEN_DOOR, &tileWidth, &tileHeight);
}

void renderMapTile(int col, int row, char tileType, gameState *game)
{
    static int tileWidth = WIDTH;
    static int tileHeight = HEIGHT;

    if (tileType == '1')
        mlx_put_image_to_window(game->mlx, game->win,
            game->images.wall, col * tileWidth, row * tileHeight);
    if (tileType == '0')
        mlx_put_image_to_window(game->mlx, game->win,
            game->images.floor, col * tileWidth, row * tileHeight);
    if (tileType == 'P')
        mlx_put_image_to_window(game->mlx, game->win,
            game->images.player, col * tileWidth, row * tileHeight);
    if (tileType == 'E')
        mlx_put_image_to_window(game->mlx, game->win,
            game->images.exit, col * tileWidth, row * tileHeight);
    if (tileType == 'C')
        mlx_put_image_to_window(game->mlx, game->win,
            game->images.collectible, col * tileWidth, row * tileHeight);
    if (tileType == 'O')
        mlx_put_image_to_window(game->mlx, game->win,
            game->images.closed_exit, col * tileWidth, row * tileHeight);
    if (tileType == 'F')
        mlx_put_image_to_window(game->mlx, game->win,
            game->images.open_exit, col * tileWidth, row * tileHeight);
}

int renderMap(gameState *game)
{
    int row;
    int col;


    row = 0;
    while (row < game->row)
    {
        col = 0;
        while (col < game->col)
        {
            renderMapTile(col, row, game->map[row][col], game);
            col++;
        }
        row++;
    }
    return (0);
}
