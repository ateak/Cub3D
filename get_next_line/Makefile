NAME	= get_next_line.a

SRCS	= get_next_line.c
			
INCL	= get_next_line.h

OBJS	= $(SRCS:.c=.o)

FLAGS	= -Wall	-Wextra -Werror -g 

.c.o:
		$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

$(NAME)	:	$(OBJS)
			ar rcs $(NAME) $(OBJS)

$(OBJS)	:	$(INCL)

all	:		$(NAME)

bonus	:	all

clean	:
			rm -f $(OBJS)

fclean	:	clean
			rm -f $(NAME)

re	:		fclean all

.PHONY	:	all clean fclean re
