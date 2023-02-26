#ifndef FORM_HPP
#define FORM_HPP

# include <iostream>
#include "Bureaucrat.hpp"

class Form
{
	private:
		const std::string _name;
		bool _signed;
		const int _gradeSign;
		const int _gradeExec;

	public:
		Form();	// Default Constructor
		Form(std::string name, int gradeSi, int gradeEx);	// Fields Constructor
		Form(const Form& c);	// Copy Constructor
		Form & operator=(const Form& a); // Copy Assignement Operator
		~Form();	// Destructor

		std::string getName() const;
		bool getSigned() const;
		int getGradeSign() const;
		int getGradeExec() const;

		void beSigned(const Bureaucrat& b);

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

std::ostream & operator<<(std::ostream& o, const Form& a);

#endif
