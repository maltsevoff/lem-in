# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omaltsev <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/26 16:06:57 by omaltsev          #+#    #+#              #
#    Updated: 2018/11/05 17:24:28 by omaltsev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAGS = -c -Wall -Wextra -Werror

INC = includes/

SRC = *.c

OBJ = *.o

all: $(NAME)

$(NAME):
	@gcc $(FLAGS) -I$(INC) $(SRC)
	@ar -r $(NAME) $(OBJ)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
