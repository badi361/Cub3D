NAME = cub3d
CC = gcc
FLAGS = -Wall -Wextra -Werror
FREAMS = -framework OpenGL -framework AppKit

MLX = ./mlx/libmlx.a
LIBFT = ./libft/libft.a
GNL = ./get_next_line/get_next_line.a

all: $(NAME)

$(NAME): *.o $(MLX) $(LIBFT) $(GNL)
	$(CC) $(FLAGS) -o $(NAME) *.o $(MLX) $(LIBFT) $(GNL) $(FREAMS)

*.o: *.c
	$(CC) $(FLAGS) -c *.c

$(MLX):
	@make -C ./mlx

$(LIBFT):
	@make -C ./libft

$(GNL):
	@make -C ./get_next_line

clean:
	rm -f *.o
	@make clean -C ./libft
	@make clean -C ./get_next_line

fclean: clean
	rm -f cub3d
	@make fclean -C ./libft
	@make fclean -C ./get_next_line

re:fclean all