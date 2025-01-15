BINARY		= megaphone
CC			= c++
OPT			= -g3
FLAGS		= -Wall -Wextra -Werror -std=c++98 $(OPT)
INCLUDE		= $(shell find . -type f -name *.hpp)
CPPFILES	= $(shell find . -type f -name *.cpp)
OBJ			= $(CPPFILES:.cpp=.o)

all: $(BINARY)

$(BINARY): $(OBJ)
	$(CC) $(FLAGS) $(INCLUDE) -o $@ $(OBJ)

%.o:%.cpp
	$(CC) $(FLAGS) -c $^

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(BINARY)

re: fclean all

.phony: all clean fclean re