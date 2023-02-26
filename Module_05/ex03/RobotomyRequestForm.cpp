#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm("Default", 72, 45)
{
	std::cout << "RobotomyRequestForm default constructor" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& c): AForm(c), _target(c._target)
{
	std::cout << "RobotomyRequestForm copy constructor" << std::endl;
	*this = c;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("Robotomy Request Form", 72, 45), _target(target)
{
	std::cout << "RobotomyRequestForm fields constructor" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

RobotomyRequestForm & RobotomyRequestForm::operator=(const RobotomyRequestForm& c)
{
	std::cout << "RobotomyRequestForm copy assignement operator" << std::endl;
	if (this != &c)
	{
		this->_target = c._target;
	}
	return *this;
}

// --------------------------- Getters && Setters -------------------------- //
//there is get method in hpp
// std::string RobotomyRequestForm::getTarget() const
// {
// 	return _target;
// }

void RobotomyRequestForm::execute(Bureaucrat const &execute) const
{
	if (this->_target.length() == 0)
		throw std::out_of_range("No target");
	else if (execute.getGrade() > this->getGradeExec())
		throw GradeTooLowException();
	if (rand() % 2)
		std::cout << this->_target << " has been robotomized successfully" << std::endl;
	else
		std::cout << this->_target << " has not been robotomized" << std::endl;
}

