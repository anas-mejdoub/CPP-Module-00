SRC=phonebook.cpp
OBJ=$(SRC:.cpp=.o)
CC =c++
FLAGS=-Wall -Wextra -Werror
NAME =phonebook

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o : %.cpp
	$(CC) $(FLAGS) -c $< -o $@

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re: fclean all