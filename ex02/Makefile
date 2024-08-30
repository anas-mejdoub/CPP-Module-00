SRC=  tests.cpp Account.cpp
OBJ=$(SRC:.cpp=.o)
CC=c++
FLAGS=-Wall -Wextra -Werror
NAME=Account

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o : %.cpp %.hpp
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

