# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ateak <ateak@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/22 16:34:27 by ateak             #+#    #+#              #
#    Updated: 2022/10/29 15:13:40 by ateak            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
NAME_BONUS = cub3D_bonus

SRCS			=	./srcs/main.c\
					./srcs/init.c\
					./srcs/utils.c\
					./srcs/parser_first_check.c\
					./srcs/parser_main.c\
					./srcs/parser_get_colour_texture_info.c\
					./srcs/parser_save_colour.c\
					./srcs/parser_save_texture.c\
					./srcs/parser_check_player_find_map_size.c\
					./srcs/parser_check_map_border.c\
					./srcs/working_with_textures.c\
					./srcs/wall_casting_prt1.c\
					./srcs/wall_casting_prt2.c\
					./srcs/game_loop.c\
					./srcs/key_action_move.c\
					./srcs/key_action_rotate.c\

SRCS_BONUS		=	./srcs_bonus/main_bonus.c\
					./srcs_bonus/init_bonus.c\
					./srcs_bonus/utils_bonus.c\
					./srcs_bonus/parser_first_check_bonus.c\
					./srcs_bonus/parser_main_bonus.c\
					./srcs_bonus/parser_get_colour_texture_info_bonus.c\
					./srcs_bonus/parser_save_colour_bonus.c\
					./srcs_bonus/parser_save_texture_bonus.c\
					./srcs_bonus/parser_check_player_find_map_size_bonus.c\
					./srcs_bonus/parser_check_map_border_bonus.c\
					./srcs_bonus/working_with_textures_bonus.c\
					./srcs_bonus/wall_casting_prt1_bonus.c\
					./srcs_bonus/wall_casting_prt2_bonus.c\
					./srcs_bonus/game_loop_bonus.c\
					./srcs_bonus/key_action_move_bonus.c\
					./srcs_bonus/key_action_rotate_bonus.c\
					./srcs_bonus/realize_doors_bonus.c\
					./srcs_bonus/realize_minimap_bonus.c\
					./srcs_bonus/realize_mouse_rotate_bonus.c\


OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

OBJS_DIR		= srcs/
OBJS_BONUS_DIR	= srcs_bonus/

HEADER 			= ./srcs/cub3d.h
HEADER_BONUS 	= ./srcs_bonus/cub3d_bonus.h

CFLAGS 			= -Wall -Werror -Wextra

RM 				= rm -rf

# only for MacOS graphics not arm.
MLX_FLAGS 		= -lmlx -L ./minilibx -framework OpenGL -framework AppKit

# FOR LIBS
LIBDIR		= libft

LIBFT_LIB	= $(LIBDIR)/libft.a

LIB			= -L$(LIBDIR) -lft

GNL			= get_next_line/get_next_line.a

MLX_DIR		= minilibx


all: $(NAME)

$(NAME): $(OBJS)
			make -C $(LIBDIR)
			make -C get_next_line
			make -C $(MLX_DIR)
			$(CC) $(CFLAGS) $(LIBFT_LIB) $(GNL) $(OBJS) $(MLX_FLAGS) -o $(NAME)

$(OBJS_DIR)%.o:	$(OBJS_DIR)%.c $(HEADER)
				$(CC) $(CFLAGS) -c $< -o $@


bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJS_BONUS)
			make -C $(LIBDIR)
			make -C get_next_line
			make -C $(MLX_DIR)
			$(CC) $(CFLAGS) $(LIBFT_LIB) $(GNL) $(OBJS_BONUS) $(MLX_FLAGS) -o $(NAME_BONUS)

$(OBJS_BONUS_DIR)%.o:	$(OBJS_BONUS_DIR)%.c $(HEADER_BONUS)
						$(CC) $(CFLAGS) -c $< -o $@

clean:
		make clean -C $(LIBDIR)
		make clean -C get_next_line
		make clean -C $(MLX_DIR)
		$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	make fclean -C libft
	make fclean -C get_next_line
	$(RM) $(NAME) $(NAME_BONUS)

re: fclean all

rebonus: fclean bonus

.PHONY: all bonus clean fclean re rebonus
