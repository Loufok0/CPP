NAME = phonebook

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS =	contact.cpp \
 		$(NAME).cpp \

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

re: fclean all

