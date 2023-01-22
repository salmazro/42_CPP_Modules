NAME = harl
SOURCES = Harl.cpp\
			main.cpp

OBJECTS = $(SOURCES:.cpp=.o)
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
CXX = c++
${NAME}: $(OBJECTS)
		$(CXX) $(CXXFLAGS) -o harl $(OBJECTS)
all : ${NAME}
bonus :
clean :
		rm -f ${OBJECTS}
fclean : clean
		rm -f ${NAME}
re : fclean all
