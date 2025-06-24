SRC = $(shell find ./ -name '*.cpp')
INC = $(shell find ./ -name '*.hpp')
OBJ = $(SRC:.cpp=.o)
CC = c++
RM = rm -f
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = bureaucrat

all: $(NAME)

$(NAME): $(OBJ) $(INC)
	$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: clean
