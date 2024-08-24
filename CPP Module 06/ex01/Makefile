NAME = Serializer
FLAGS = -Wall -Wextra -Werror
STD = -std=c++98
CC = c++
SRCS = main.cpp Serializer.cpp

all: $(NAME)

$(NAME):
	$(CC) $(STD) $(FLAGS) -o $(NAME) $(SRCS)
	@echo "\033[0;32mDone\033[m"

clean:
	@rm -f $(NAME)
	@echo "\033[0;34mclean\033[m"

re: clean all

.PHONY: all clean re