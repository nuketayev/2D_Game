LIBFT_DIR    = libft/
LIBFT_NAME   = libft.a
LIBFT        = $(LIBFT_DIR)$(LIBFT_NAME)

MINILIBX_PATH = ./minilibx-linux
MLXFLAGS      = -L$(MINILIBX_PATH) -lmlx -I$(MINILIBX_PATH) -lXext -lX11

NAME          = so_long
CC            = cc
FLAGS         = -Wall -Werror -Wextra -g
SRC           = main.c map_validation.c map_backend.c map_rendering.c game.c game_utils.c
OBJ           = $(SRC:.c=.o)

all: $(LIBFT) $(NAME)

$(LIBFT):
	@make -s -C $(LIBFT_DIR)

$(NAME): $(OBJ) $(LIBFT)
	@$(RM) $(NAME)
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME) $(MLXFLAGS) $(LIBFT)  -s

clean:
	@make clean -s -C $(LIBFT_DIR)
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(LIBFT_DIR)$(LIBFT_NAME)

re: fclean all

.PHONY: all clean fclean re
