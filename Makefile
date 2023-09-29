NAME		= cub3D

LBFT		= libft/libft.a

GNL			= get_next_line/get_next_line.a

MLX			= mlx/libmlx.a

SRCS        :=      change_map.c \
					check_map.c \
					check_map_2.c \
					destroy_game.c \
					get_map.c \
					get_next_line/get_next_line.c \
					get_next_line/get_next_line_utils.c \
					init.c \
					main.c \
					map_control.c \
					mlx_key.c \
					player_move.c \
					player_move_2.c \
					raycasting.c \
					raycasting_2.c \
					texture_init.c \
					textures_to_pixel.c \
					utils.c \
					utils_v2.c \
					utils_v3.c \
					utils_v4.c \
					utils_v5.c \

CC			= gcc

FLAGS		= -Wall -Wextra -Werror -framework OpenGL -framework AppKit

all : $(NAME)

$(NAME)	: $(LBFT) $(GNL) $(MLX) $(SRCS)
		@$(CC) $(SRCS) $(MLX) $(LBFT) $(FLAGS) $(GNL) -o $(NAME)

$(LBFT):
		@make -C libft

$(GNL):
		@make -C get_next_line
	
$(MLX):
		@make -C mlx

clean :
		@rm -rf $(NAME)
		@make fclean -C libft
		@make fclean -C get_next_line
		@make clean -C mlx

fclean : clean

re : clean all

.PHONY : all clean fclean re