NAME		= harl

CC			= c++

FLAGS		= -Wall -Werror -Wextra -std=c++98

INCLUDES	= Harl.hpp

SOURCES		= main.cpp Harl.cpp

OBJECTS		= $(SOURCES:.cpp=.o)

all:
	@$(MAKE) $(NAME)

$(NAME): $(OBJECTS)
	@$(CC) $(FLAGS) $(OBJECTS) -o $(NAME)

clean: 
	@rm -rf *.o

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re