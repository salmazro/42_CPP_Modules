# include "AForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "Intern.hpp"

void	test_intern(Bureaucrat &b1, Bureaucrat &b2, std::string const &formName, std::string const &target)
{
	Intern someRandomIntern;
	AForm *form = someRandomIntern.makeForm(formName, target);
	if (form)
	{
		std::cout << "Intern creates " << *form << std::endl;
		b1.signForm(*form);
		b2.executeForm(*form);
		delete form;
	}
}

int main()
{
    Bureaucrat Brad("Brad", 50);
	Bureaucrat Chad("Chad", 79);
	std::cout << "----------------------------------------------------------------" << std::endl;
	test_intern(Brad, Chad, "Robotomy Request", "Bender");
	std::cout << "----------------------------------------------------------------" << std::endl;
	test_intern(Brad, Chad, "Presidential Pardon", "Bender");
	std::cout << "----------------------------------------------------------------" << std::endl;
	test_intern(Brad, Chad, "Shrubbery Creation", "Bender");
	std::cout << "----------------------------------------------------------------" << std::endl;
    return (0);
}
