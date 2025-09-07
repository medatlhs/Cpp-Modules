SRC = $(shell find ./ -name '*.cpp')
INC = $(shell find ./ -name '*.hpp')
OBJ = $(SRC:.cpp=.o)
CC = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = Identify_Real_Type

all: $(NAME)

%.o: %.cpp $(INC)
	$(CC) $(CPPFLAGS) -c $< -o $@
	
$(NAME): $(OBJ) $(INC)
	$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: clean
