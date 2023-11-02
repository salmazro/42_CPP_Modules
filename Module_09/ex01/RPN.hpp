#ifndef RPN
# define RPN

#include <iostream>
#include <cstdlib>
#include <string>
#include <stack>
#include <sstream>
#include <stdexcept>

// Declaration of a class named Rpn
class Rpn
{
	private:

		// Stack to store operands
		std::stack<double> stack;

		// Input RPN expression
		std::string argv;

	public:

		// Default constructor
		Rpn(void);

		// Constructor that initializes the Rpn class with an RPN expression
		Rpn(std::string notion);

		// Copy constructor
		Rpn(const Rpn &other);

		// Assignment operator overload
		Rpn &operator=(const Rpn &rhs);

		// Destructor
		~Rpn();

		// Function to evaluate the RPN expressio
		void calua();

		// Custom exception class for general errors
		class ErrorHappen : public std::exception
		{
			const   char *what() const throw();
		};

		// Custom exception class for division by zero errors
		class DivisionByZero : public std::exception
		{
			const   char *what() const throw();
		};
};

#endif
