# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ateak <ateak@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/22 16:34:27 by ateak             #+#    #+#              #
#    Updated: 2022/10/15 19:42:49 by ateak            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	cub3D
NAME_BONUS		=	cub3D_bonus

SRCS			=	./srcs/main.c\

SRCS_BONUS		=	

LIBDIR			= 	libft
LIBFT_LIB		= 	$(LIBDIR)/libft.a
LIB				=	-L$(LIBDIR) -lft
MLXDIR			= 	minilibx
MLX_LIB			=	$(MLXDIR)/libmlx.a
MLX				=	-L$(MLXDIR) -lft
	
					
HEADER 			= 	./srcs/cub3d.h	
HEADER_BONUS 	= 	./srcs_bonus/cub3d_bonus.h	

OBJS			=	$(SRCS:%.c=%.o)
OBJS_BONUS 		= 	$(SRCS_BONUS:%.c=%.o)
OBJS_DIR		=	srcs/
OBJS_DIR_BONUS	=	srcs_bonus/

CFLAGS			=	-Wall -Wextra -Werror 
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

$(NAME_BONUS):	$(LIBFT_LIB) $(OBJS_BONUS)
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