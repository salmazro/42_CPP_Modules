# include "AForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

int main()
{
    Bureaucrat Brad("Brad", 1);
	Bureaucrat Chad("Chad", 150);
	ShrubberyCreationForm Shurb("Shurb");
	RobotomyRequestForm Rob("Rob");
	PresidentialPardonForm Press("Press");
	std::cout << std::endl;

	std::cout << "----------------------------------------------------------------" << std::endl;
	std::cout << "----------------------------------------------------------------" << std::endl;

	Brad.signForm(Shurb);
	Brad.executeForm(Shurb);
	std::cout << Shurb << std::endl;
	std::cout << "----------------------------------------------------------------" << std::endl;
	Brad.signForm(Rob);
	Brad.executeForm(Rob);
	std::cout << Rob << std::endl;
	std::cout << "----------------------------------------------------------------" << std::endl;
	Brad.signForm(Press);
	Brad.executeForm(Press);
	std::cout << Press << std::endl;
	std::cout << "----------------------------------------------------------------" << std::endl;
	std::cout << "----------------------------------------------------------------" << std::endl;
	Chad.signForm(Shurb);
	Chad.executeForm(Shurb);
	std::cout << Shurb << std::endl;
	std::cout << "----------------------------------------------------------------" << std::endl;
	Chad.signForm(Rob);
	Chad.executeForm(Rob);
	std::cout << Rob << std::endl;
	std::cout << "----------------------------------------------------------------" << std::endl;
	Chad.signForm(Press);
	Chad.executeForm(Press);
	std::cout << Press << std::endl;
	std::cout << "----------------------------------------------------------------" << std::endl;
	std::cout << "----------------------------------------------------------------" << std::endl;


	return (0);
}
