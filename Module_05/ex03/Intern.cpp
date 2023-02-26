#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern default constructor" << std::endl;
}

Intern::Intern(const Intern& c)
{
	std::cout << "Intern copy constructor" << std::endl;
	*this = c;
}

Intern::~Intern()
{
	std::cout << "Intern destructor called" << std::endl;
}

Intern & Intern::operator=(const Intern& c)
{
	std::cout << "Intern copy assignement operator" << std::endl;
	(void)c;
	return *this;
}

AForm *Intern::makeForm(std::string const & formName, std::string const & target)
{
	std::cout << "makeForm" << std::endl;
	std::string names[3] = {"Robotomy Request", "Presidential Pardon", "Shrubbery Creation"};
	makeFormPtr ptrs[3] = {&Intern::_makeRForm, &Intern::_makePForm, &Intern::_makeSForm};
	try
	{
		for (int i = 0; i < 3; i++)
		{
			if (names[i] == formName)
				return (this->*ptrs[i])(target);
		}
		throw Intern::UnknownFormException();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return NULL;
}

AForm* Intern::_makeRForm(std::string const & target)
{
	std::cout << "makeRForm" << std::endl;
	return new RobotomyRequestForm(target);
}

AForm* Intern::_makePForm(std::string const & target)
{
	std::cout << "makePForm" << std::endl;
	return new PresidentialPardonForm(target);
}

AForm* Intern::_makeSForm(std::string const & target)
{
	std::cout << "makeSForm" << std::endl;
	return new ShrubberyCreationForm(target);
}

const char* Intern::UnknownFormException::what() const throw()
{
	return "Unknown form";
}
