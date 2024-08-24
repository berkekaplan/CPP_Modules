NAME	= RPN
CC		= c++
FLAGS	= -Wall -Wextra -Werror -std=c++98
RM		= rm -rf
HEADER	= RPN.hpp
SRCS    = RPN.cpp main.cpp
OBJS    = $(SRCS:.cpp=.o)

all: coffee $(NAME)

$(NAME): $(OBJS)
	@echo "\033[1;3;30m\n  Reverse Polish Notation by ahkalama\033[m\n"
	@ $(CC) $(FLAGS) $(OBJS) -o $(NAME)
	@echo "\033[3;30m		 Done\033[m\n"

%.o: %.cpp $(HEADER)
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJS)
	@echo "\033[3;30m\n 	       Cleaning...\033[m\n"

fclean: clean
	@$(RM) $(NAME)

re: fclean all

coffee:

	@echo	"\n░▒▓███████▓▒░░▒▓███████▓▒░░▒▓███████▓▒░  "
	@echo	"░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░ "
	@echo	"░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░ "
	@echo	"░▒▓███████▓▒░░▒▓███████▓▒░░▒▓█▓▒░░▒▓█▓▒░ "
	@echo	"░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░ "
	@echo	"░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░ "
	@echo	"░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░ \n"                                      
                                       

.PHONY: all clean fclean re
