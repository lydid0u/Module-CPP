# **************************************************************************** #
#																			  #
#														 :::	  ::::::::	#
#	Makefile										   :+:	  :+:	:+:	#
#													 +:+ +:+		 +:+	  #
#	By: lboudjel <lboudjel@student.42.fr>		  +#+  +:+	   +#+		 #
#												 +#+#+#+#+#+   +#+			#
#	Created: 2024/10/14 17:15:50 by lboudjel		  #+#	#+#			  #
#	Updated: 2024/10/14 17:15:50 by lboudjel		 ###   ########.fr		#
#																			  #
# **************************************************************************** #

NAME	= megaphone
SRC		= megaphone.cpp
OBJ		= $(SRC:.cpp=.o)
CC		= c++
FLAGS	= -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re