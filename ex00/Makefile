SRC=megaphone.cpp
OBJ=$(SRC:.cpp=.o)
CC=c++
CFLAGS=-Wall -Wextra -Werror
NAME=megaphone

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all