# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/28 17:36:37 by lcorinna          #+#    #+#              #
#    Updated: 2022/07/12 19:23:31 by lcorinna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_MINIRT	=	miniRT

MINIRT		=	minirt.c program_completion.c\
				parser.c vec3_one.c vec3_two.c scene.c camera.c sphere.c \
				calibration.c \
				draw.c buttons.c trace_ray.c sphere_interesect.c 

OBJ_MINIRT	=	$(SRC:.c=.o)

FLAG_MLX	=	-lmlx -framework OpenGL -framework AppKit

CFLAGC		=	-Wall -Wextra -Werror -MMD -O3 -msse4 -march=native -g -fsanitize=address # Leaks --atExit -- ./miniRT

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

