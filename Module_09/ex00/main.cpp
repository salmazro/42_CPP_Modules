#include "BitcoinExchange.hpp"

// Check if there are exactly two command-line arguments
int main(int arc, char **argv)
{
	if (arc == 2)
	{
		try
		{
			// Create an instance of the BitcoinExchange class with the provided file as input
			BitcoinExchange bit(argv[1]);

			// Determine the size of the input file
			size_t file =  bit.size_for_input_file();

			// Check if the input file is not empty
			if (file)
			{
				// Fill the map with data from the database
				bit.fill_Map_DB();

				// Print all data from the map
				bit.print_all();
			}

			else
			{
				// If the input file is empty, display an error message
				std::cout << "The input file is empty" << std::endl;
				return 0;
			}
		}

		catch(const std::exception& e)
		{
			// Handle exceptions by displaying an error message
			std::cerr << e.what() << '\n';
		}
	}

	else
		// If the number of command-line arguments is not 2, display an error message
		std::cout << "Error: could not open file." << std::endl;
}
