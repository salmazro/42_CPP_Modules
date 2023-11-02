#include "RPN.hpp"

int main(int argc, char* argv[])
{
	// Check if the correct number of command-line arguments is provided
	if (argc != 2)
	{
		std::cerr << "Usage: " << argv[0] << " \"RPN expression\"" << std::endl;
		return 1; // Return an error code
	}

	try
	{
		// Create an instance of the Rpn class with the provided RPN expression
		Rpn calculator(argv[1]);

		// Calculate the result of the RPN expression
		calculator.calua();
	}

	catch(const std::exception& e)
	{
		// Handle exceptions by displaying an error message
		std::cerr << e.what() << '\n';
	}

	return 0; // Return success
}
