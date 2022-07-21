# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/28 17:36:37 by lcorinna          #+#    #+#              #
#    Updated: 2022/07/21 16:52:45 by lcorinna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

N_MINIRT	=	miniRT

MINIRT		=	minirt.c program_completion.c \
				parser.c vec3_one.c vec3_two.c scene.c camera.c sphere.c \
				light.c \
				# calibration.c \
				# draw.c buttons.c trace_ray.c sphere_interesect.c 

OBJ_MINIRT	=	$(SRC:.c=.o)

FLAG_MLX	=	-lmlx -framework OpenGL -framework AppKit

CFLAGC		=	-Wall -Wextra -Werror -MMD -g -fsanitize=address -O3 -msse4 -march=native # Leaks --atExit -- ./miniRT

SRC_PATH	=	./srcs/

SRC			=	$(addprefix $(SRC_PATH), $(MINIRT))

DEP			=	$(SRC:.c=.d)

PATH_LIBFT	=	./libft/

LIBFT		=	libft.a 

all:			libmake $(N_MINIRT)

libmake: 
	make -C $(PATH_LIBFT)
	cp $(PATH_LIBFT)$(LIBFT) $(LIBFT)
	
$(N_MINIRT):	$(OBJ_MINIRT)
	cc $(CFLAGS) $(FLAG_MLX) $(LIBFT) $(OBJ_MINIRT) -o $@

%.o:			%.c minirt.h Makefile
	gcc $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_MINIRT) $(DEP) $(LIBFT)
	make clean -C $(PATH_LIBFT)

fclean:			clean
	rm -rf $(N_MINIRT)
	make fclean -C $(PATH_LIBFT)

re:				fclean all

-include $(DEP)

.PHONY:		all libmake clean fclean re	

