#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		std::string _target;

	public:
		PresidentialPardonForm();	// Default Constructor
		PresidentialPardonForm(std::string const str);	// Fields Constructor
		PresidentialPardonForm(const PresidentialPardonForm& c);	// Copy Constructor
		PresidentialPardonForm & operator=(const PresidentialPardonForm& a); // Copy Assignement Operator
		~PresidentialPardonForm();	// Destructor

		std::string getTarget() const;

		void execute(Bureaucrat const & executor) const;
};

#endif
