#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("Shrubbery Creation Form", 145, 137), _target("Classified")
{
	std::cout << "ShrubberyCreationForm default constructor" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& c): AForm(c), _target(c._target)
{
	std::cout << "ShrubberyCreationForm copy constructor" << std::endl;
	*this = c;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("Shrubbery Creation Form", 145, 137), _target(target)
{
	std::cout << "ShrubberyCreationForm fields constructor" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(const ShrubberyCreationForm& c)
{
	std::cout << "ShrubberyCreationForm copy assignement operator" << std::endl;
	if (this != &c)
	{
		this->_target = c._target;
	}
	return *this;
}

// --------------------------- Getters && Setters -------------------------- //
//there is no get method in hpp
// std::string ShrubberyCreationForm::getTarget() const
// {
// 	return _target;
// }

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (this->_target.length() == 0)
		throw std::out_of_range("No target");
	else if (executor.getGrade() > this->getGradeExec())
		throw GradeTooLowException();
	else
	{
		std::ofstream file;

		file.open((this->_target + "_shrubbery").c_str(), std::fstream::trunc | std::fstream::out);
		if (!file.is_open())
			throw std::runtime_error("File could not be opened");
		file << "             &&  & " << std::endl;
		file << "           &&& &&  & &&" << std::endl;
		file << "     && &'\' /&\' |& ()|/ @, &&" << std::endl;
		file << "     &'\' /(/&/&||/& /_/)_&/_&" << std::endl;
		file << "   &() &\' /&| ()|/&\' / '%' & ()" << std::endl;
		file << "  &_\' _&&_\'  |& |&&/&__%_/_& &&" << std::endl;
		file << "&&   && & &| & &| /& & % ()& /&&" << std::endl;
		file << " ()&_---()&\' &\' |&&-&&--%---()~" << std::endl;
		file << "     &&     \' |||" << std::endl;
		file << "              |||" << std::endl;
		file << "              |||" << std::endl;
		file << "              |||" << std::endl;
		file << "              |||" << std::endl;
		file << "   --, -=-~  .-^- _ + ---" << std::endl;
		file.close();

	}
}
