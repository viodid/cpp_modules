BINARY		:= megaphone
COMPILER	:= c++
FLAGS		:= -Wall -Wextra -Werror -std=c++98
OPT			:= -g3
INCLUDE		:= $(shell find . | grep \.hpp)
CFILES		:= $(shell find . -type f -name "*.cpp")
OBJ			:= $(CFILES:.c=.o)

all: $(BINARY)

$(BINARY): obj
	$(COMPILER) $(FLAGS) $(INCLUDE) $(OBJ) -o $(BINARY)

obj:
	$(COMPILER) $(FLAGS) $(OPT) -c $(CFILES)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(BINARY)

re: fclean all

.phony: all clean fclean re