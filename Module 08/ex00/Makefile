SRC = main.cpp
INC = easyfind.hpp
OBJ = $(SRC:.cpp=.o)
CC = c++
RM = rm -f
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = easyfind

all: $(NAME)

%.o: %.cpp $(INC)
	$(CC) $(CPPFLAGS) -c $< -o $@
	
$(NAME): $(OBJ)
	$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)

clean: 
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean
