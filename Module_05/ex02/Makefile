NAME = bureaucrat
SRCS = Bureaucrat.cpp\
			AForm.cpp\
			PresidentialPardonForm.cpp\
			RobotomyRequestForm.cpp\
			ShrubberyCreationForm.cpp\
			main.cpp
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
