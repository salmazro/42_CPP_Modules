#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include "AForm.hpp"
# include <stdlib.h> /* rand */
# include <time.h> /* time */

class RobotomyRequestForm: public AForm
{
	private:
		std::string _target;

	public:
		RobotomyRequestForm();	// Default Constructor
		RobotomyRequestForm(std::string const str);	// Fields Constructor
		RobotomyRequestForm(const RobotomyRequestForm& c);	// Copy Constructor
		RobotomyRequestForm & operator=(const RobotomyRequestForm& a); // Copy Assignement Operator
		~RobotomyRequestForm();	// Destructor

		// std::string getTarget() const;

		void execute(Bureaucrat const & executor) const;
};

#endif

