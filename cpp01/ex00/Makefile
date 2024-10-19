# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/17 18:04:10 by lboudjel          #+#    #+#              #
#    Updated: 2024/10/17 18:09:47 by lboudjel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= brainz
SRC		= Zombie.cpp \
			newZombie.cpp \
			randomChump.cpp \
			main.cpp
OBJ		= $(SRC:%.cpp=%.o)
INCL	= Zombie.hpp 
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