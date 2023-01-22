#include "Harl.hpp"

int main()
{
	Harl obj;
	std::string complain;

	std::cout << "Enter the complain \"INFO/WARNING/ERROR/DEBUG\": ";
	std::cin >> complain;
	std::cout << std::endl;
	obj.complain(complain);

	return 0;
}
