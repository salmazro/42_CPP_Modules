#include "easyfind.hpp"

// int main()
// {
// 	std::vector<int>	vec;
// 	vec.push_back(1);
// 	vec.push_back(9);
// 	vec.push_back(32);
// 	vec.push_back(4242);
// 	vec.push_back(-42);
//     std::vector<int>::iterator it = easyfind(vec, 4242);
//     std::cout << "It returns: " << *it << std::endl;
// 	it = easyfind(vec, 32);
//     std::cout << "It returns: " << *it << std::endl;
// 	it = easyfind(vec, 9);
//     std::cout << "It returns: " << *it << std::endl;
// 	it = easyfind(vec, 1);
//     std::cout << "It returns: " << *it << std::endl;
// 	it = easyfind(vec, -42);
//     std::cout << "It returns: " << *it << std::endl;
// 	try
// 	{
//         std::vector<int>::iterator it = easyfind(vec, 123);
//         std::cout << "It returns: " << *it << std::endl;
// 	}
// 	catch (const std::exception &e)
// 	{
// 		std::cerr << e.what() << '\n';
// 	}
// 	return (0);
// }

int	main()
{
	std::vector<int>			vect;
	std::vector<int>::iterator	it;

	for (int i = 0; i < 10; i+=2)
		vect.push_back(i);
	try
	{
		it = easyfind(vect, 4);
		std::cout << "iterator: " << *it << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		it = easyfind(vect, 20);
		std::cout << "iterator: " << *it << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
