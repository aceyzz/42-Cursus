# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/03 13:34:59 by cedmulle          #+#    #+#              #
#    Updated: 2023/11/04 09:22:33 by cedmulle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ---------------------------------------------------------------------------- #
# 								Variables									   #
# ---------------------------------------------------------------------------- #
SRC		= ft_printf.c print_first.c print_second.c
OBJ		= ${SRC:.c=.o}

CFLAGS	= -Wall -Werror -Wextra
HEAD	= ft_printf.h
CC		= gcc
AR		= ar rcs
RM		= rm -f
NAME	= libftprintf.a
# ---------------------------------------------------------------------------- #
# 									Regles								       #
# ---------------------------------------------------------------------------- #
all:		${NAME}

${NAME}:	${OBJ}
	@${AR} ${NAME} ${OBJ}
	@echo "Compilation successful."

%.o:		%.c ${HEAD}
	@${CC} ${CFLAGS} -c $< -o $@

clean:
	@${RM} ${OBJ} ${OBJB}
	@echo "Objects files deleted."

fclean:		clean
	@${RM} ${NAME}
	@echo "${NAME} deleted."

re:			fclean all
