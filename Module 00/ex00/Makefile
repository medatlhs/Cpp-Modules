SRC = megaphone.cpp
CC = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic
NAME = megaphone

OBJ = ${SRC:.cpp=.o}

all: ${NAME}

${NAME}: ${OBJ}
		${CC} ${CPPFLAGS} ${OBJ} -o ${NAME}

clean:
		rm -f ${OBJ}

fclean: clean
		rm -f ${NAME}

re : fclean all

.PHONY: clean
