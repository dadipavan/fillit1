# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tidadi <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/04 20:32:29 by tidadi            #+#    #+#              #
#    Updated: 2019/01/04 20:32:41 by tidadi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
FLAGS = -Wall -Wextra -Werror
SRCS = main.c output.c tetrimino.c piece.c list.c backtrack.c board.c
OBJ = ${SRCS:.c=.o}

all: $(NAME)
$(NAME):
	gcc $(FLAGS) -I. -c $(SRCS)
	gcc $(FLAGS) $(OBJ) -o $(NAME)
clean:
	/bin/rm -f $(OBJ)
fclean: clean
	/bin/rm -f $(NAME)
re: fclean all
