# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/29 17:08:11 by lboudjel          #+#    #+#              #
#    Updated: 2025/02/21 20:58:51 by lboudjel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= PMergeMe

SRCS_NAMES  = PMergeMe.cpp main.cpp
OBJS_NAMES  = $(SRCS_NAMES:.cpp=.o)

DIR_INCL	= include
DIR_SRCS	= srcs
DIR_OBJS	= objs

SRCS		= $(addprefix $(DIR_SRCS)/,$(SRCS_NAMES))
OBJS		= $(addprefix $(DIR_OBJS)/,$(OBJS_NAMES))

CC		  = c++
CFLAGS	  = -std=c++98 #-Wall -Wextra -Werror 
INC		 = -I$(DIR_INCL)
CDFLAGS	 = -MMD -MP

DEPS		= $(OBJS:.o=.d)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) -o $(NAME)

$(DIR_OBJS)/%.o: $(DIR_SRCS)/%.cpp
	@mkdir -p $(DIR_OBJS)
	$(CC) $(CFLAGS) $(INC) $(CDFLAGS) -c $< -o $@

leaks: $(NAME)
	valgrind ./$(NAME)

clean:
	rm -rf $(DIR_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re leaks