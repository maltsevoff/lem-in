# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omaltsev <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/16 18:00:56 by omaltsev          #+#    #+#              #
#    Updated: 2019/03/16 18:02:00 by omaltsev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := lem-in

SRC_DIR := ./src/
OBJ_DIR := ./obj/
INC_DIR := ./inc/
LIB_DIR := ./lib/

SRC = main.c

OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_DIR := $(LIB_DIR)libft/
LIBFT_INC := $(LIBFT_DIR)includes/
LIBFT_FLAGS := -lft -L $(LIBFT_DIR)

CC_FLAGS := -Wall -Wextra -Werror

# LINK_FLAGS := $(LIBFT_FLAGS)

LINK_FLAGS = -lmlx -lft -L$(LIBFT_DIR) -framework OpenGL -framework AppKit

HEADER_FLAGS := -I $(INC_DIR) -I $(LIBFT_INC)

CC := gcc

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	@$(CC) $(OBJ) $(LINK_FLAGS) -o $(NAME)

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: %.c
	@$(CC) -c $< -o $@ $(CC_FLAGS) $(HEADER_FLAGS)

$(LIBFT):
	@make -C $(LIBFT_DIR)

clean:
	@rm -f $(OBJ)
	@make clean -C $(LIBFT_DIR)

fclean: clean
	@rm -f $(NAME)
	@rm -rf $(OBJ_DIR)
	@make fclean -C $(LIBFT_DIR)

re: fclean all

vpath %.c $(SRC_DIR)
