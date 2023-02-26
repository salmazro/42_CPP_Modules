#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat(): name("Default"), grade(150)
{
	std::cout << "Bureaucrat default constructor" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& c)
{
	std::cout << "Bureaucrat copy constructor" << std::endl;
	*this = c;
}

Bureaucrat::Bureaucrat(std::string n, int g): name(n)
{
	std::cout << "Bureaucrat fields constructor" << std::endl;
	if (g < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (g > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		grade = g;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor called" << std::endl;
}

Bureaucrat & Bureaucrat::operator=(const Bureaucrat& c)
{
	std::cout << "Bureaucrat copy assignement operator" << std::endl;
	if (this != &c)
	{
		grade = c.grade;
	}
	return *this;
}

std::string Bureaucrat::getName() const
{
	return name;
}

int Bureaucrat::getGrade() const
{
	return grade;
}

void Bureaucrat::signForm(AForm &f)
{
	std::cout << "Sign Form" << std::endl;
	try {
		f.beSigned(*this);
		std::cout << this->getName() << " signs " << f.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << this->getName() << " cannot sign " << f.getName() << " because sign grade too low." <<std::endl;
		std::cout << e.what() << std::endl;
	}
}

void Bureaucrat::incrementGrade()
{
	std::cout << "Increment Grade" << std::endl;
	try {
		if (grade > 1 && grade < 151)
			grade--;
		else
			throw Bureaucrat::GradeTooHighException();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

void Bureaucrat::decrementGrade()
{
	std::cout << "Decrement Grade" << std::endl;
	try {
		if (grade > 0 && grade < 150)
			grade++;
		else
			throw Bureaucrat::GradeTooLowException();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const & form)
{
	std::cout << "Execute Form" << std::endl;
	try {
		if (this->getGrade() <= form.getGradeExec())
		{
			form.execute(*this);
			std::cout << this->getName() << " executes " << form.getName() << std::endl;
		}
		else
			throw Bureaucrat::GradeTooLowException();
	}
	catch (std::exception &e)
	{
		std::cerr << this->getName() << " cannot execute " << form.getName() << " because execute grade too low." <<std::endl;
		std::cout << e.what() << std::endl;
	}
}

std::ostream & operator<<(std::ostream & o, Bureaucrat const & a)
{
	o << a.getName() << ", bureaucrat grade " << a.getGrade() << std::endl;
	return o;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}
