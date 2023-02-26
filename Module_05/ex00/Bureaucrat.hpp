#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
	private:
		const std::string name;
		int grade;
		//Bureaucrat();

	public:
		Bureaucrat();
		Bureaucrat(std::string n, int g);	// Default Constructor
		Bureaucrat(const Bureaucrat& c);	// Copy Constructor
		Bureaucrat & operator=(const Bureaucrat& a); // Copy Assignement Operator
		~Bureaucrat();	// Destructor

		std::string getName() const;
		int getGrade() const;

		void incrementGrade();
		void decrementGrade();

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
