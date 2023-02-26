#ifndef AFORM_HPP
#define AFORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;
class AForm
{
	private:
		const std::string _name;
		bool _signed;
		const int _gradeSign;
		const int _gradeExec;

	public:
		AForm();	// Default Constructor
		AForm(std::string name, int gradeSi, int gradeEx);	// Fields Constructor
		AForm(const AForm& c);	// Copy Constructor
		AForm & operator=(const AForm& a); // Copy Assignement Operator
		virtual ~AForm();	// Destructor

		std::string getName() const;
		bool getSigned() const;
		int getGradeSign() const;
		int getGradeExec() const;

		void beSigned(const Bureaucrat& b);
		virtual void execute(const Bureaucrat& executor) const = 0;

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
		class FormNotSignedException : public std::exception
		{
		public:
			FormNotSignedException() {}
			virtual ~FormNotSignedException() throw() {}
			virtual const char* what() const throw();
		};
};

std::ostream & operator<<(std::ostream& o, const AForm& a);

#endif
