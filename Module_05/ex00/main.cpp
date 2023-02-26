# include "Bureaucrat.hpp"

int main()
{
	try
	{
		std::cout << "----------------------------------------------------------------" << std::endl;
		Bureaucrat b("Bureaucrat 1", 70);
		std::cout << b;
		b.incrementGrade();
		std::cout << b;
		b.decrementGrade();
		std::cout << b;
		std::cout << "----------------------------------------------------------------" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::cout << "----------------------------------------------------------------" << std::endl;
		Bureaucrat l("Bureaucrat 2", 1);
		std::cout << l;
		l.incrementGrade();
		std::cout << l;
		l.decrementGrade();
		std::cout << l;
		std::cout << "----------------------------------------------------------------" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		std::cout << "----------------------------------------------------------------" << std::endl;
		Bureaucrat h("Bureaucrat 3", 150);
		std::cout << h;
		h.decrementGrade();
		std::cout << h;
		h.incrementGrade();
		std::cout << h;
		std::cout << "----------------------------------------------------------------" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return (0);
}
