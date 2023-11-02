#ifndef BITCOINEXCHANGE
#define BITCOINEXCHANGE

#include <iostream>
#include <map>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <fstream>
#include <string>
#include <limits>
#include <string.h>

// Declaration of a class named BitcoinExchange
class BitcoinExchange
{
	private:

		// A map to store Bitcoin exchange data
		std::map<std::string, double> data;

 		// Input file stream
		std::ifstream fileStream;

		// Database file stream
		std::ifstream database;

	public:

		// Constructor to initialize the class with a file input
		BitcoinExchange(std::string file_input);

		// Assignment operator overload
		BitcoinExchange &operator=(const BitcoinExchange &rhs);

		// Copy constructor
		BitcoinExchange(const BitcoinExchange &other);

		// Destructor
		~BitcoinExchange();

		// Current line number
		size_t	current_line;

		// Function to fill the map with data from the database
		void	fill_Map_DB();

		// Function to check the validity of a line
		int		check_line(std::string line);

		// Function to print all data in the map
		void	print_all();

		// Function to determine the size of the input file
		size_t	size_for_input_file();
};

#endif
