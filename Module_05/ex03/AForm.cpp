#include "AForm.hpp"

AForm::AForm(): _name("Default"), _signed(false), _gradeSign(0), _gradeExec(0)
{
	std::cout << "AForm default constructor" << std::endl;
}

AForm::AForm(const AForm& c): _name(c._name), _signed(c._signed), _gradeSign(c._gradeSign), _gradeExec(c._gradeExec)
{
	std::cout << "AForm copy constructor" << std::endl;
	*this = c;
}

AForm::AForm(std::string name, int gradeSi, int gradeEx): _name(name), _signed(false), _gradeSign(gradeSi), _gradeExec(gradeEx)
{
	std::cout << "AForm fields constructor" << std::endl;
	if (gradeSi > 150 || gradeEx > 150)
		throw AForm::GradeTooLowException();
	else if (gradeSi < 1 || gradeEx < 1)
		throw AForm::GradeTooHighException();
	else
		std::cout << "AForm " << name << " created" << " signing grade " << this->_gradeSign << std::endl;
}

AForm::~AForm()
{
	std::cout << "AForm destructor called" << std::endl;
}

AForm & AForm::operator=(const AForm& c)
{
	std::cout << "AForm copy assignement operator" << std::endl;
	if (this != &c)
	{
		this->_signed = c._signed;
	}
	return *this;
}

std::string AForm::getName() const
{
	return this->_name;
}

bool AForm::getSigned() const
{
	return this->_signed;
}

int AForm::getGradeSign() const
{
	return this->_gradeSign;
}

int AForm::getGradeExec() const
{
	return this->_gradeExec;
}

void AForm::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() <= this->_gradeSign)
	{
		this->_signed = true;
	}
	else
	{
		std::cout << "AForm " << this->_name << " couldn’t sign " << b.getName() << " because his grade is too low" << std::endl;
		throw AForm::GradeTooLowException();
	}
}

std::ostream & operator<<(std::ostream& o, const AForm& a)
{
	o << "AForm " << a.getName() << " is " << (a.getSigned() ? "signed" : "unsigned") << " and requires a grade of " << a.getGradeSign() << " to be signed and a grade of " << a.getGradeExec() << " to be executed" << std::endl;
	return o;
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

const char* AForm::FormNotSignedException::what() const throw()
{
	return "Form not signed";
}
