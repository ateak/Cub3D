# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ateak <ateak@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/22 16:34:27 by ateak             #+#    #+#              #
#    Updated: 2022/10/24 14:22:23 by ateak            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	cub3D
NAME_BONUS		=	cub3D_bonus

SRCS			=	get_next_line/get_next_line.c\
					get_next_line/get_next_line_utils.c\
					./srcs/main.c\
					./srcs/init.c\
					./srcs/utils.c\
					./srcs/first_check.c\
					./srcs/parser_main.c\
					./srcs/parser_get_colour_texture_info.c\
					./srcs/parser_save_colour.c\
					./srcs/parser_save_texture.c\
					./srcs/parser_check_player_find_map_size.c\
					./srcs/parser_check_map_border.c\
									

SRCS_BONUS		=	get_next_line/get_next_line.c\
					get_next_line/get_next_line_utils.c\
					./srcs_bonus/main_bonus.c\
					./srcs_bonus/init_bonus.c\
					./srcs_bonus/utils_bonus.c\
					./srcs_bonus/first_check_bonus.c\
					./srcs_bonus/parser_main_bonus.c\
					./srcs_bonus/parser_get_colour_texture_info_bonus.c\
					./srcs_bonus/parser_save_colour_bonus.c\
					./srcs_bonus/parser_save_texture_bonus.c\
					./srcs_bonus/parser_check_player_find_map_size_bonus.c\
					./srcs_bonus/parser_check_map_border_bonus.c\

LIBDIR			= 	libft
LIBFT_LIB		= 	$(LIBDIR)/libft.a
LIB				=	-L$(LIBDIR) -lft
MLXDIR			= 	minilibx
MLX_LIB			=	$(MLXDIR)/libmlx.a
MLX				=	-L$(MLXDIR) -lft
	
					
HEADER 			= 	./srcs/cub3d.h\
					get_next_line/get_next_line.h\	
HEADER_BONUS 	= 	./srcs_bonus/cub3d_bonus.h\
					get_next_line/get_next_line.h\

OBJS			=	$(SRCS:%.c=%.o)
OBJS_BONUS 		= 	$(SRCS_BONUS:%.c=%.o)
OBJS_DIR		=	srcs/
OBJS_DIR_BONUS	=	srcs_bonus/

CFLAGS			=	-Wall -Wextra -Werror -g
MLX_FLAGS		=	-lmlx -framework OpenGL -framework AppKit

RM = rm -f

.PHONY	:	all clean fclean re make_lib

all		:	$(NAME)

$(NAME)	:	$(LIBFT_LIB) $(MLX_LIB) $(OBJS)
			$(CC) $(CFLAGS) $(MLX_FLAGS) -I$(LIBDIR) $(LIB) -I$(MLXDIR) $(MLX) $(OBJS)  -o ${NAME}

$(OBJS_DIR)%.o: 	$(OBJS_DIR)%.c $(HEADER)
					$(CC) $(CFLAGS) -I$(LIBDIR) -I$(MLXDIR) -c $< -o $@
	
$(LIBFT_LIB):	make_lib

make_lib	:	
		make -C $(LIBDIR) 
		make -C $(MLXDIR)

bonus	: $(NAME_BONUS)

$(NAME_BONUS):	$(LIBFT_LIB) $(MLX_LIB) $(OBJS_BONUS)
				$(CC) $(CFLAGS) $(MLX_FLAGS) -I$(LIBDIR) $(LIB) -I$(MLXDIR) $(MLX) $(OBJS_BONUS)  -o ${NAME_BONUS} 

$(OBJS_DIR_BONUS)%.o: 	$(OBJS_DIR_BONUS)%.c $(HEADER_BONUS)
						$(CC) $(CFLAGS) -I$(LIBDIR) -I$(MLXDIR) -c $< -o $@

clean	:
	make clean -C $(LIBDIR) 
	make clean -C $(MLXDIR)
	$(RM) $(OBJS) $(OBJS_BONUS) 

fclean	: 	clean
	$(RM) $(NAME) $(NAME_BONUS)

re		:	fclean all