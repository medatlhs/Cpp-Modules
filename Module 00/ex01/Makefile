SRC = ./src/main.cpp ./src/contact.cpp ./src/phonebook.cpp ./src/utils.cpp
INCLUDE = ./includes/contact.hpp ./includes/phonebook.hpp
CC = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic
NAME = crappy

OBJ = ${SRC:.cpp=.o}

all: ${NAME}

${NAME}: ${OBJ} ${INCLUDE}
		${CC} ${CPPFLAGS} ${OBJ} -o ${NAME}

clean:
		rm -f ${OBJ}

fclean: clean
		rm -f ${NAME}

re : fclean all

.PHONY: clean
