#ifndef INTERN_HPP
#define INTERN_HPP

# include <iostream>
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class AForm;

class Intern
{
    private:
    	AForm* _makeSForm(std::string const & target);
	    AForm* _makeRForm(std::string const & target);
	    AForm* _makePForm(std::string const & target);

    public:
	    Intern();	// Default Constructor
        Intern(const Intern& c);	// Copy Constructor
	    Intern & operator=(const Intern& a); // Copy Assignement Operator
	    virtual ~Intern();	// Destructor

	    AForm* makeForm(std::string const & formName, std::string const & target);

	    class UnknownFormException : public std::exception
	    {
		    virtual const char* what() const throw();
        };

	    typedef AForm* (Intern::*makeFormPtr)(std::string const & target);
};

#endif
