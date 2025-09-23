SRC = $(shell find ./ -name '*.cpp')
INC = $(shell find ./ -name '*.hpp')
TEMP = $(shell find ./ -name '*.tpp')
OBJ = $(SRC:.cpp=.o)
CC = c++
RM = rm -f
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = Array

all: $(NAME) 

%.o: %.cpp $(INC) $(TEMP)
	$(CC) $(CPPFLAGS) -c $< -o $@
	
$(NAME): $(OBJ) $(INC)
	$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)

clean: 
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: clean

