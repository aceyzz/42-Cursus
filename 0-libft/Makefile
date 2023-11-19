# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/03 13:34:59 by cedmulle          #+#    #+#              #
#    Updated: 2023/10/09 17:43:29 by cedmulle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ---------------------------------------------------------------------------- #
# 								Variables									   #
# ---------------------------------------------------------------------------- #
SRC		= ft_isalpha.c ft_isalnum.c ft_isdigit.c ft_isascii.c \
				ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c \
				ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c \
				ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c \
				ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c \
				ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c \
				ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
				ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
OBJ		= ${SRC:.c=.o}

SRCB	= ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
				ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
				ft_lstmap.c
OBJB	= ${SRCB:.c=.o}

CFLAGS	= -Wall -Werror -Wextra
HEAD	= libft.h
CC		= gcc
AR		= ar rcs
RM		= rm -f
NAME	= libft.a
# ---------------------------------------------------------------------------- #
# 									Regles								       #
# ---------------------------------------------------------------------------- #
all:		${NAME}

${NAME}:	${OBJ}
	@${AR} ${NAME} ${OBJ}
	@echo "Compilation successful."
	@echo "Library created."

%.o:		%.c ${HEAD}
	@${CC} ${CFLAGS} -c $< -o $@

clean:
	@${RM} ${OBJ} ${OBJB}
	@echo "Objects files deleted."

fclean:		clean
	@${RM} ${NAME}
	@echo "The ${NAME} deleted."

re:			fclean all

bonus:		${OBJB}
	@${AR} ${NAME} ${OBJB}
	@echo "Bonus added."
