
NAME	= phonebook
SRC		= phonebook.cpp \
			contact.cpp \
			
OBJ		= $(SRC:%.cpp=%.o)
INCL	= PhoneBook.hpp \
			contact.hpp
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

