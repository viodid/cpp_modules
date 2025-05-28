BINARY		= serialize
CC			= c++
OPT			= -g3
FLAGS		= -Wall -Wextra -Werror -std=c++98 $(OPT)
SRC			= src
CPPFILES	= $(shell find $(SRC) -type f -name '*.cpp')
TESTCPP		= $(shell find $(SRC) -type f -name '*.cpp' | grep -v 'main.cpp')
OBJ			= $(CPPFILES:.cpp=.o)
TESTOBJ		= $(TESTCPP:.cpp=.o)

all: $(BINARY)

$(BINARY): $(OBJ)
	$(CC) $(FLAGS) -o $@ $(OBJ)

test: $(TESTOBJ)
	$(CC) $(FLAGS) -o $@ $(TESTOBJ)

%.o:%.cpp
	$(CC) $(FLAGS) -c $^ -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(BINARY)

re: fclean all

.phony: all clean fclean re
