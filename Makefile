# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vgiordan <vgiordan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/17 13:41:23 by jdefayes          #+#    #+#              #
#    Updated: 2023/02/23 14:27:51 by vgiordan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

###############
##
#Arguments

NAME	= fractol

###############
##
#Sources

SRCS	=	main.c\
			events.c\
			render.c\
			zoom.c\
			fract_generator.c\
			initialization.c\
			utils.c\
			swiss_fract.c
			

OBJS	= ${SRCS:.c=.o}
CFLAGS	=  -g
CC		= gcc
RM		= rm -f

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o ${<:.c=.o}

$(NAME): $(OBJS)
	make -C mlx
	make -C libft
## -C change directory
	cp mlx/libmlx.dylib .
## copy libmlx dans le fichier ou l on est
	$(CC) $(CFLAGS) $(OBJS) -fsanitize=address -Llibft -lft -Lmlx -lmlx -framework OpenGL -framework AppKit -I libft -o  $(NAME)

all: ${NAME}

clean:
	$(RM) $(OBJS)
	make clean -C mlx
	make clean -C libft
	${RM} libmlx.dylib

fclean: clean
	${RM} ${NAME}
	make fclean -C libft

re: fclean all

.PHONY: all clean fclean re


