NAME		= zombie

CC			= c++

FLAGS		= -Wall -Werror -Wextra -std=c++98

INCLUDES	= Zombie.hpp

SOURCES		= main.cpp newZombie.cpp randomChump.cpp Zombie.cpp

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