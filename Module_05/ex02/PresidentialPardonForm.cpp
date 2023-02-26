#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("Default", 25, 5), _target("Default")
{
	std::cout << "PresidentialPardonForm default constructor" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& c): AForm(c), _target(c._target)
{
	std::cout << "PresidentialPardonForm copy constructor" << std::endl;
	*this = c;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("Presidential Pardon Form", 25, 5), _target(target)
{
	std::cout << "PresidentialPardonForm fields constructor" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

PresidentialPardonForm & PresidentialPardonForm::operator=(const PresidentialPardonForm& c)
{
	std::cout << "PresidentialPardonForm copy assignement operator" << std::endl;
	if (this != &c)
	{
		this->_target = c._target;
	}
	return *this;
}

// std::string PresidentialPardonForm::getTarget() const
// {
// 	return _target;
// }

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (this->_target.length() == 0)
		throw std::out_of_range("Target is empty");
	else if (this->getGradeExec() < executor.getGrade())
		throw GradeTooLowException();
	else if (this->getSigned() == false)
		throw AForm::FormNotSignedException();
	else
		std::cout << this->_target << " has been pardoned by Zafod Beeblebrox." << std::endl;

}
