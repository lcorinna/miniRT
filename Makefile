# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/28 17:36:37 by lcorinna          #+#    #+#              #
#    Updated: 2022/08/06 17:41:26 by lcorinna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

N_MINIRT	=	miniRT

MINIRT		=	minirt.c program_completion.c \
				parser/parser.c parser/parser_utils.c \
				parser/pars_color.c parser/pars_point.c \
				parser/skip_char.c parser/ambiant.c parser/camera.c\
				parser/light.c parser/shapes_list.c \
				parser/sphere.c parser/plane.c parser/cylinder.c \
				vec3_one.c vec3_two.c scene.c \
				draw.c \
				#trace_ray.c sphere_interesect.c calibration.c buttons.c

OBJ_MINIRT	=	$(SRC:.c=.o)

FLAG_MLX	=	-Lmlx -lmlx -framework OpenGL -framework AppKit

CFLAGC		=	-Wall -Wextra -Werror -MMD -g -fsanitize=address -O3 -msse4 -march=native # Leaks --atExit -- ./miniRT

SRC_PATH	=	./srcs/

SRC			=	$(addprefix $(SRC_PATH), $(MINIRT))

DEP			=	$(SRC:.c=.d)

PATH_LIBFT	=	./libft/
LIBFT		=	libft.a

PATH_MLX	=	./mlx/
MLX			=	libmlx.a

all:			mlxmake libmake $(N_MINIRT)

libmake: 
	make -C $(PATH_LIBFT)
	cp $(PATH_LIBFT)$(LIBFT) $(LIBFT)

mlxmake:
	make -C $(PATH_MLX)
	cp $(PATH_MLX)$(MLX) $(MLX)
	
$(N_MINIRT):	$(OBJ_MINIRT)
	cc $(CFLAGS) $(FLAG_MLX) $(LIBFT) $(MLX) $(OBJ_MINIRT) -o $@

%.o:			%.c minirt.h Makefile
	cc $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_MINIRT) $(DEP) $(LIBFT) $(MLX)
	make clean -C $(PATH_LIBFT)
	make clean -C $(PATH_MLX)

fclean:			clean
	rm -rf $(N_MINIRT)
	make fclean -C $(PATH_LIBFT)
	make clean -C $(PATH_MLX)

re:				fclean all

-include $(DEP)

.PHONY:		all libmake clean fclean re	

