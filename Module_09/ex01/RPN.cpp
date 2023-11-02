#include "RPN.hpp"

// Constructor that initializes Rpn with an RPN expression
Rpn::Rpn(std::string notion)
{
	this->argv = notion;
}

// Copy constructor
Rpn::Rpn(const Rpn &other)
{
	this->argv = other.argv;
	this->stack = other.stack;
}

// Assignment operator overload
Rpn &Rpn::operator=(const Rpn &rhs)
{
	if (this != &rhs)
	{
		argv = rhs.argv;
		stack = rhs.stack;
	}

	return (*this);
}

// Default constructor
Rpn::Rpn() {}

// Destructor
Rpn::~Rpn() {}

// Custom exception class for general errors
const char* Rpn::ErrorHappen::what() const throw(){return "Error";}

// Custom exception class for division by zero errors
const char* Rpn::DivisionByZero::what() const throw(){return "Error: Division by zero";}

void Rpn::calua()
{
	// Check if the first character is a digit and the second character is an operator
	if(isdigit(argv[0]) && (argv[1] == '-' || argv[1] == '+'|| argv[1] == '*' || argv[1] == '/'))
		throw ErrorHappen();

	// Create an input string stream to tokenize the RPN expression
	std::istringstream iss(this->argv);
	std::string token;
	double left;
	double right;
	double total;

	left = 0;
	right = 0;
	total = 0;

	// Tokenize and process the RPN expression
	while (iss >> token)
	{
		if (token == "+" || token == "-" || token == "*" || token == "/")
		{
			// Check if there are at least two operands on the stack
			if (stack.size() < 2)
				throw ErrorHappen();

			// Perform the specified operation based on the token
			if (token == "+")
			{
				right  = stack.top();
				stack.pop();
				left = stack.top();
				stack.pop();
				total = left + right;
				stack.push(total);
			}

			else if (token == "-")
			{
				right  = stack.top();
				stack.pop();
				left = stack.top();
				stack.pop();
				total = left - right;
				stack.push(total);
			}

			else if (token == "*")
			{
				right  = stack.top();
				stack.pop();
				left = stack.top();
				stack.pop();
				total = left * right;
				stack.push(total);
			}

			else if (token == "/")
			{
				right  = stack.top();
				stack.pop();
				left = stack.top();
				stack.pop();

				// Check for division by zero
				if (right == 0)
					throw DivisionByZero();

				total = left / right;
				stack.push(total);
			}
		}

		else if (isdigit(token[0]))
		{
			// Convert the token to a double and push it onto the stack
			double number;
			number = atoi(token.c_str());

			// Check if the number is greater than 10
			if (number > 10)
				throw ErrorHappen();

			stack.push(number);
		}

		else
			throw ErrorHappen(); // Throw an error for invalid tokens
	}

	// Check if there is exactly one value left on the stack
	if (stack.size() != 1)
		std::cout << "Missing operators, numbers are still in stack" << std::endl;

	else
		std::cout << stack.top() << std::endl; // Print the final result
}
