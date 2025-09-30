NAME =DIAMOND 

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -Wno-shadow -Wshadow -std=c++98

SRCS =	main.cpp \
		ClapTrap.cpp \
		ScavTrap.cpp\
		FragTrap.cpp\
		DaimondTrap.cpp\

OBJS = $(SRCS:.cpp=.o)

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(OBJS) $(CXXFLAGS) -o $(NAME)
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

