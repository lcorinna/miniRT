# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/28 17:36:37 by lcorinna          #+#    #+#              #
#    Updated: 2022/06/30 19:53:27 by lcorinna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_MINIRT	=	miniRT

MINIRT		=	minirt.c parser.c scene.c\
				vec3_one.c vec3_two.c \
				camera.c sphere_interesect.c sphere.c trace_ray.c \
				buttons.c

OBJ_MINIRT	=	$(SRC:.c=.o)

FLAG_MLX	=	-lmlx -framework OpenGL -framework AppKit

CFLAGC		=	-Wall -Wextra -Werror -MMD -g #-fsanitize=address # Leaks --atExit -- ./miniRT

SRC_PATH	=	./srcs/

SRC			=	$(addprefix $(SRC_PATH), $(MINIRT))

DEP			=	$(SRC:.c=.d)

all:			$(NAME_MINIRT)

$(NAME_MINIRT):	$(OBJ_MINIRT)
	cc $(CFLAGS) $(FLAG_MLX) $(OBJ_MINIRT) -o $@

%.o:			%.c minirt.h Makefile
	gcc $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_MINIRT) $(DEP)

fclean:			clean
	rm -rf $(NAME_MINIRT)

re:				fclean all

-include $(DEP)

.PHONY:		all libmake clean fclean re	

