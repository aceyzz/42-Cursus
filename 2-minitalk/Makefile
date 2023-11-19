# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/15 09:29:39 by cedmulle          #+#    #+#              #
#    Updated: 2023/11/19 09:10:12 by cedmulle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ---------------------------------------------------------------------------- #
#                                 Variables                                    #
# ---------------------------------------------------------------------------- #
# ------ EXECUTABLES ------ #
SRV			= server
CLI			= client
# ------ DIRECTORIES ------ #
INC			= inc/
SRV_DIR		= src/srv/
CLI_DIR		= src/cli/
OBJ_DIR		= obj/
# ----- SOURCES FILES ----- #
SRC_SRV		= $(SRV_DIR)server.c
SRC_CLI		= $(CLI_DIR)client.c
SRCS		= $(SRC_SRV) $(SRC_CLI)
# ------- FT_PRINTF ------- #
PF_DIR		= ./utils/ft_printf/
PF_SRC		= $(wildcard $(PF_DIR)*.c)
PF_OBJ		= $(patsubst $(PF_DIR)%.c,$(OBJ_DIR)ft_printf/%.o,$(PF_SRC))
PF_LIB		= libftprintf.a
# ------ COMPILATION ------ #
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra -I
LDFLAGS		= -L./lib -lftprintf
RM			= rm -f

# ---------------------------------------------------------------------------- #
#                                 Fonctions                                    #
# ---------------------------------------------------------------------------- #
# Règle générale ------------------------------------------------------------- #
all:
				@echo "\033[1;34mLoading...\033[0m"
				@$(MAKE) $(SRV) $(CLI) $(PF_LIB) > /dev/null
				@echo "\033[1;36mCompilation of \"$(SRV)\" successful √\033[0m"
				@echo "\033[1;36mCompilation of \"$(CLI)\" successful √\033[0m"
				@echo "\033[1;36mCompilation of \"$(PF_LIB)\" successful √\033[0m"

# Création de l'éxécutable serveur ------------------------------------------- #
$(SRV): 		$(OBJ_DIR)server/server.o $(PF_LIB)
				@$(CC) $(CFLAGS) $(INC) $(OBJ_DIR)server/server.o -o $(SRV) $(LDFLAGS)

# Création de l'éxécutable client -------------------------------------------- #
$(CLI): 		$(OBJ_DIR)client/client.o $(PF_LIB)
				@$(CC) $(CFLAGS) $(INC) $(OBJ_DIR)client/client.o -o $(CLI) $(LDFLAGS)

# Création librairie ft_printf ----------------------------------------------- #
$(PF_LIB):		$(PF_OBJ)
				@ar rc $(PF_LIB) $(PF_OBJ)
				@ranlib $(PF_LIB)
				@mkdir -p ./lib/
				@mv $(PF_LIB) ./lib/

# Création des fichiers objets serveur --------------------------------------- #
$(OBJ_DIR)server/server.o:	$(SRV_DIR)server.c 
				@mkdir -p $(@D)
				@$(CC) $(CFLAGS) $(INC) -c $< -o $@

# Création des fichiers objets client ---------------------------------------- #
$(OBJ_DIR)client/client.o:	$(CLI_DIR)client.c 
				@mkdir -p $(@D)
				@$(CC) $(CFLAGS) $(INC) -c $< -o $@

# Création des fichiers objets printf ---------------------------------------- #
$(OBJ_DIR)ft_printf/%.o:	$(PF_DIR)%.c 
				@mkdir -p $(@D)
				@$(CC) $(CFLAGS) $(INC) -c $< -o $@

# Suppression fichiers objets ------------------------------------------------ #
clean:
				@$(RM) -r $(OBJ_DIR)
				@echo "\033[1;35mAll objects files succesfully deleted √\033[0m"

# Suppression fichiers objets + éxécutables + librairie printf --------------- #
fclean: 		clean
				@$(RM) $(SRV) $(CLI)
				@$(RM) -r ./lib
				@echo "\033[1;35m${SRV} succesfully deleted √\033[0m"
				@echo "\033[1;35m${CLI} succesfully deleted √\033[0m"
				@echo "\033[1;35m${PF_LIB} succesfully deleted √\033[0m"

# Suppression fichiers objets + éxécutables + librairie printf + recompile --- #
re: 			fclean all

bonus:			all

.PHONY: 		start all clean fclean re
