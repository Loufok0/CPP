NAME = UnnecessaryViolence

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS =	main.cpp \
		HumanA.cpp \
		HumanB.cpp \
		Weapon.cpp

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(NAME)
	@echo "$(NAME) compiled!"

clean:

fclean: clean
	$(RM) $(NAME)

re:
	@make fclean
	@make all

