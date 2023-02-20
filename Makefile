# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vgiordan <vgiordan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/17 13:41:23 by jdefayes          #+#    #+#              #
#    Updated: 2023/02/20 16:51:02 by vgiordan         ###   ########.fr        #
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
			utils.c
			

OBJS	= ${SRCS:.c=.o}
CFLAGS	=  -g
CC		= gcc
RM		= rm -f
MAKE 	= make

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o ${<:.c=.o}

$(NAME): $(OBJS)
	$(MAKE) -C mlx
## -C change directory
	cp mlx/libmlx.dylib .
## copy libmlx dans le fichier ou l on est
	$(CC) $(CFLAGS) $(OBJS) -fsanitize=address -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

all: ${NAME}

clean:
	$(RM) $(OBJS)
	make clean -C mlx
	${RM} libmlx.dylib

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re


