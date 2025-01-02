# 2D Game Project

Welcome to the 2D Game project! This project is a 2D game developed using C and the MiniLibX library. The game involves navigating a player character through a map, collecting items, and reaching the exit.

## Features

- 2D graphics using MiniLibX
- Player movement and controls
- Collectibles to gather
- Exit to reach and win the game
- Basic game mechanics and logic

## Installation

### Dependencies

- Make sure you have the following dependencies installed:
  - gcc (GNU Compiler Collection)
  - make (Build automation tool)
  - X11 libraries (for MiniLibX)

### Compilation

1. Clone the repository:
   ```sh
   git clone https://github.com/nuketayev/2D_Game.git
   cd 2D_Game
   ```

2. Compile the project using the provided Makefile:
   ```sh
   make
   ```

## Usage

### Running the Game

To start the game, run the following command:
```sh
./so_long ./maps/[map_name].ber
```
Replace `[map_name]` with the name of the map file you want to use.

### Controls

- `W` or `Up Arrow`: Move up
- `A` or `Left Arrow`: Move left
- `S` or `Down Arrow`: Move down
- `D` or `Right Arrow`: Move right
- `ESC`: Exit the game

### Game Mechanics

- Collect all the collectibles (represented by 'C' in the map and as money in the game) to unlock the exit.
- Reach the exit (represented by 'E' in the map and as a plane in the game) to win the game.
- Avoid walls (represented by '1' in the map and as a concrete in the game) 
- and navigate through the open spaces (represented by '0' in the map and as grass in the game).

## Troubleshooting

### Common Issues

1. **Game crashes on startup:**
   - Ensure you have all the required dependencies installed.
   - Check if the map file is correctly specified and exists in the `./maps` directory.

2. **Player movement is not working:**
   - Make sure you are using the correct controls as specified in the usage section.
   - Verify that the game window is in focus when trying to control the player.

3. **Graphics not displaying correctly:**
   - Ensure that the MiniLibX library is properly installed and linked.
   - Check if the image files for the game elements are present in the `./elements` directory.

If you encounter any other issues, feel free to open an issue on the GitHub repository.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

## Acknowledgements

- MiniLibX library for providing the graphics framework.
- 42 School for the project inspiration and guidance.
