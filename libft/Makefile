# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/25 21:27:37 by lcorinna          #+#    #+#              #
#    Updated: 2022/08/09 12:54:38 by lcorinna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

LIST_1	=	ft_putstr_fd.c ft_strncmp.c ft_strlen.c ft_atoi.c ft_isdigit.c \
			get_next_line_utils.c get_next_line.c

O_FILES	=	$(LIST_1:.c=.o)

all:		$(NAME)

$(NAME):	$(O_FILES)
	ar rcs $(NAME) $?

%.o:		%.c libft.h Makefile
	cc -Wall -Wextra -Werror -c $< -o $@

clean:
	rm -rf $(O_FILES)

fclean:		clean
	rm -rf $(NAME)

re:			fclean $(NAME)

.PHONY:		all clean fclean re