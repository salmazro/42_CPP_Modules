#include "PmergeMe.hpp"

// Function to check if the command-line arguments are valid positive numbers
// Returns 1 if all arguments are valid, 0 otherwise
int	check_Is_Digit(char **argv)
{
	int i;

	i = 1;
	while (argv[i])
	{
		int j = 0;

		while (argv[i][j])
		{
			// Skip leading spaces
			while (argv[i][j] == ' ')
				j++;

			// Check if the character is a digit
			if (isdigit(argv[i][j]))
				j++;

			// Check for a negative sign
			else if (argv[i][j] == '-')
			{
				std::cout << "the input must be only positive number" << std::endl;
				return 0;
			}

			// Invalid character found
			else
			{
				std::cout << "the input must be only number" << std::endl;
				return 0;
			}

		}

		i++;
	}

	return 1;
}

// Main function to process command-line arguments and perform merging and sorting operations
int	main(int arc, char **argv)
{
	// Check if command-line arguments are valid positive numbers
	if(check_Is_Digit(argv))
	{
		// Create a vector to store all sets of numbers
		std::vector<std::vector<int> > allNumbers;

		// Iterate through command-line arguments
		for (int i = 1; i < arc; ++i)
		{
			std::vector<int> numbers;
			std::istringstream iss(argv[i]);
			int num;

			// Parse the argument and extract integers
			while (iss >> num)
			{
				numbers.push_back(num);
			}

			// If numbers were extracted, add them to the vector
			if (!numbers.empty())
				allNumbers.push_back(numbers);
		}

		// Create an instance of the PmergeMe class and perform merging and sorting
		PmergeMe merg = PmergeMe(allNumbers);
	}

}
