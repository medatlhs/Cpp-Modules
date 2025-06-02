SRC = $(shell find ./source/ -name '*.cpp')
INC = $(shell find ./Inc/ -name '*.hpp')
OBJ = $(SRC:.cpp=.o)
CC = c++
RM = rm -f
CPPFLAGS = -Wall -Wextra -Werror -Wshadow -std=c++98 -pedantic
NAME = morphism

all: $(NAME)

$(NAME): $(OBJ) $(INC)
	$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: clean
