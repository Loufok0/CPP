NAME = ANIMAL

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS =	main.cpp \
		Animal.cpp\
		Cat.cpp \
		Dog.cpp\
		WrongAnimal.cpp\
		WrongCat.cpp \
		Brain.cpp\

OBJS = $(SRCS:.cpp=.o)

RM = rm -f

all: $(NAME)

$(NAME):
	$(CXX) $(SRCS) $(CXXFLAGS) -o $(NAME)
	@echo "$(NAME) compiled!"

%.o: %.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:
	@make fclean
	@make all

