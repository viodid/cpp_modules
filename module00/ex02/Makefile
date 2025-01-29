BINARY		= phonebook
CC			= c++
OPT			= -g3
FLAGS		= -Wall -Wextra -Werror -std=c++98 $(OPT)
SRC			= .
CPPFILES	= $(shell find $(SRC) -type f -name '*.cpp')
OBJ			= $(CPPFILES:.cpp=.o)

all: $(BINARY)

$(BINARY): $(OBJ)
	$(CC) $(FLAGS) -o $@ $(OBJ)

%.o:%.cpp
	$(CC) $(FLAGS) -c $^ -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(BINARY)

re: fclean all

.phony: all clean fclean re