#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
	private:
		const std::string name;
		int grade;
		//Bureaucrat();

	public:
		Bureaucrat(); // Default Constructor
		Bureaucrat(std::string n, int g);	// Fields Constructor
		Bureaucrat(const Bureaucrat& c);	// Copy Constructor
		Bureaucrat & operator=(const Bureaucrat& a); // Copy Assignement Operator
		virtual ~Bureaucrat();	// Destructor

		std::string getName() const;
		int getGrade() const;

		void incrementGrade();
		void decrementGrade();
		void signForm(AForm & f);
		void executeForm(AForm const & form);

		class GradeTooHighException : public std::exception
		{
		public:
			GradeTooHighException() {}
			virtual ~GradeTooHighException() throw() {}
			virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
		public:
			GradeTooLowException() {}
			virtual ~GradeTooLowException() throw() {}
			virtual const char* what() const throw();
		};
};

std::ostream & operator<<(std::ostream & o, Bureaucrat const & a);


#endif
