NAME		= unnecessaryViolence

CC			= c++

FLAGS		= -Wall -Werror -Wextra -std=c++98

INCLUDES	= HumanA.hpp HumanB.hpp Weapon.hpp

SOURCES		= main.cpp HumanA.cpp HumanB.cpp Weapon.cpp

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