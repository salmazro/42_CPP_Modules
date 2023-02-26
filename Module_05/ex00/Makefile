NAME = bureaucrat
SRCS = main.cpp \
		Bureaucrat.cpp
OBJS = $(SRCS:.cpp=.o)
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
CXX = c++
${NAME}: $(OBJS)
		$(CXX) $(CXXFLAGS) -o bureaucrat $(OBJS)
all : ${NAME}
bonus :
clean :
		rm -f ${OBJS}
fclean : clean
		rm -f ${NAME}
re : fclean all
