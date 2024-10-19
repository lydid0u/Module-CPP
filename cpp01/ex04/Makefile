# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/19 18:49:12 by lboudjel          #+#    #+#              #
#    Updated: 2024/10/19 18:49:47 by lboudjel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = replace

SRC 	= replace.cpp \
        	main.cpp
OBJ		= $(SRC:%.cpp=%.o)
INCL	= replace.hpp 
CC		= c++
FLAGS	= -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp $(INCL)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re