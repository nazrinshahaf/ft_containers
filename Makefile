NAME = containers
CC = c++
CFLAGS = -Wall -Wextra -Werror -pedantic
C98 = -std=c++98
SANITIZE = -fsanitize=address
RM = rm -f

SRC = vector.cpp\

MAIN = main.cpp

$(NAME):
	$(CC) $(CFLAGS) $(SANITIZE) $(MAIN) $(SRC) -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(NAME)

fclean:	clean
		$(RM) $(NAME)

re: clean all

leaks: re
	$(CC) $(CFLAGS) $(C98) $(MAIN) $(SRC) -o $(NAME)
	./$(NAME)

test: re
	$(re) ./$(NAME)

san: fclean
	$(fclean)
	$(CC) $(CFLAGS) $(C98) $(SANITIZE) $(MAIN) $(SRC) -o $(NAME)
	./$(NAME)

11: fclean
	$(CC) $(CFLAGS) -std=c++11 $(SANITIZE) $(MAIN) $(SRC) -o $(NAME)
	./$(NAME)

.PHONY:	all clean fclean re test
