SRC = ./src/Account.cpp ./src/tests.cpp
INCLUDE = ./includes/Account.hpp
CC = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic
NAME = exec

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