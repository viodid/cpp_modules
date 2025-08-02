BINARY		= PmergeMe
CC			= c++
OPT			= -g3
INCLUDES	= ./include
DEBUG		= 0
FLAGS		= -Wall -Wextra -Werror -std=c++98 $(OPT) -I$(INCLUDES) -DDEBUG=$(DEBUG)
SRC			= src
CPPFILES	= $(shell find $(SRC) -type f -name '*.cpp')
OBJ			= $(CPPFILES:.cpp=.o)

all: $(BINARY)

$(BINARY): $(OBJ)
	$(CC) $(FLAGS) -o $@ $(OBJ)

debug: DEBUG = 1
debug: fclean all

%.o:%.cpp
	$(CC) $(FLAGS) -c $^ -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(BINARY)

re: fclean all

.PHONY: all clean fclean re
