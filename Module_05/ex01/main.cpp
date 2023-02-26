# include "Bureaucrat.hpp"
# include "Form.hpp"

int main()
{
	try
	{
		std::cout << "----------------------------------------------------------------" << std::endl;
		Bureaucrat b("Bureaucrat 1", 1);
		Form f("AForm", 1, 1);
		b.signForm(f);
		std::cout << "----------------------------------------------------------------" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::cout << "----------------------------------------------------------------" << std::endl;
		Bureaucrat b("Bureaucrat 2", 150);
		Form f("BForm", 2, 1);
		b.signForm(f);
		std::cout << "----------------------------------------------------------------" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return (0);
}
