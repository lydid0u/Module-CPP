NAME        = Harl

SRCS_NAMES  = Harl.cpp \
              main.cpp
OBJS_NAMES  = $(SRCS_NAMES:.cpp=.o)

DIR_INCL    = include
DIR_SRCS    = srcs
DIR_OBJS    = objs

SRCS        = $(addprefix $(DIR_SRCS)/,$(SRCS_NAMES))
OBJS        = $(addprefix $(DIR_OBJS)/,$(OBJS_NAMES))

CC          = c++
CFLAGS      = -Wall -Wextra -Werror -std=c++98
INC         = -I$(DIR_INCL)
CDFLAGS     = -MMD -MP

DEPS        = $(OBJS:.o=.d)

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
