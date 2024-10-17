# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/17 17:57:25 by lboudjel          #+#    #+#              #
#    Updated: 2024/10/17 17:57:28 by lboudjel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= phonebook
SRC		= PhoneBook.cpp \
			Contact.cpp \
			main.cpp
OBJ		= $(SRC:%.cpp=%.o)
INCL	= PhoneBook.hpp \
			Contact.hpp
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