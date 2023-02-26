#include "Form.hpp"

Form::Form(): _name("Default"), _signed(false), _gradeSign(0), _gradeExec(0)
{
	std::cout << "Form default constructor" << std::endl;
}

Form::Form(const Form& c): _name(c._name), _signed(c._signed), _gradeSign(c._gradeSign), _gradeExec(c._gradeExec)
{
	std::cout << "Form copy constructor" << std::endl;
	*this = c;
}

Form::Form(std::string name, int gradeSi, int gradeEx): _name(name), _signed(false), _gradeSign(gradeSi), _gradeExec(gradeEx)
{
	std::cout << "Form fields constructor" << std::endl;
	if (gradeSi > 150 || gradeEx > 150)
		throw Form::GradeTooLowException();
	else if (gradeSi < 1 || gradeEx < 1)
		throw Form::GradeTooHighException();
	else
		std::cout << "Form " << name << " created" << " signing grade " << this->_gradeSign << std::endl;
}

Form::~Form()
{
	std::cout << "Form destructor called" << std::endl;
}

Form & Form::operator=(const Form& c)
{
	std::cout << "Form copy assignement operator" << std::endl;
	if (this != &c)
	{
		this->_signed = c._signed;
	}
	return *this;
}

std::string Form::getName() const
{
	return this->_name;
}

bool Form::getSigned() const
{
	return this->_signed;
}

int Form::getGradeSign() const
{
	return this->_gradeSign;
}

int Form::getGradeExec() const
{
	return this->_gradeExec;
}

void Form::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() <= this->_gradeSign)
	{
		this->_signed = true;
	}
	else
	{
		std::cout << "Form " << this->_name << " couldn’t sign " << b.getName() << " because his grade is too low" << std::endl;
		throw Form::GradeTooLowException();
	}
}

std::ostream & operator<<(std::ostream& o, const Form& a)
{
	o << "Form " << a.getName() << " is " << (a.getSigned() ? "signed" : "unsigned") << " and requires a grade of " << a.getGradeSign() << " to be signed and a grade of " << a.getGradeExec() << " to be executed" << std::endl;
	return o;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}
