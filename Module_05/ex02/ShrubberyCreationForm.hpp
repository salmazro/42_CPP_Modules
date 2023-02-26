#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm: public AForm
{
	private:
		std::string _target;
		void _createTree() const;
	public:
		ShrubberyCreationForm();	// Default Constructor
		ShrubberyCreationForm(std::string const str);	// Fields Constructor
		ShrubberyCreationForm(const ShrubberyCreationForm& c);	// Copy Constructor
		ShrubberyCreationForm & operator=(const ShrubberyCreationForm& a); // Copy Assignement Operator
		~ShrubberyCreationForm();	// Destructor

		//std::string const &getTarget();

		void execute(Bureaucrat const & executor) const;
};

#endif


