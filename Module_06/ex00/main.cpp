#include  "ScalarConverter.hpp"

int main(int ac, char **av)
{

	if (ac != 2)
		std::cout << "Error: invalid argument" << std::endl;
	else
	{
		ScalarConverter conv(av[1]);
		conv.printter();
	}
	return (0);
}
