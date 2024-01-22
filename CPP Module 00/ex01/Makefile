NAME	= phonebook

SRC		= Contact.cpp main.cpp PhoneBook.cpp

OBJ		= $(SRC:.cpp=.o)

RM		= rm -rf

CC		= c++

FLAGS	= -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(OBJ): %.o: %.cpp
	@$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
