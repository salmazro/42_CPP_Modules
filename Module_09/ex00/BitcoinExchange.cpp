#include "BitcoinExchange.hpp"

// Constructor to initialize the BitcoinExchange class with file input
BitcoinExchange::BitcoinExchange(std::string file_input) : fileStream(file_input.c_str()), database("data.csv")
{
	// Check if the input file is successfully opened
	if (!fileStream.is_open()) {
		std::cerr << "Error: could not open file " << file_input << std::endl;
	}

	// Check if the database file is successfully opened
	if (!database.is_open())
	{
		std::cerr << "Error: could not open DB file " << std::endl;
	}
}

// Copy constructor
BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	// Copy the data from the 'other' object to this object
	this->data = other.data;
}

// Assignment operator overload
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &rhs)
{
	// Check for self-assignment
	if (this != &rhs)
		this->data = rhs.data;
	return *this;
}

// Destructor to close file streams
BitcoinExchange::~BitcoinExchange()
{
	// Close the file stream for the input file
	fileStream.close();

	// Close the file stream for the database
	database.close();
}

void BitcoinExchange::fill_Map_DB()
{
	// Initialize variables
	std::string line;
	std::string header = "date,exchange_rate";

	// Read lines from the database file
	while (std::getline(database, line))
	{
		// Skip the header line
		if (line == header)
			continue;

		// Find the position of the comma in the line
		size_t commaPos = line.find(',');

		// Check if a comma was found
		if (commaPos != std::string::npos)
		{
			// Extract the date and exchange rate from the line
			std::string befor = line.substr(0, commaPos);
			std::string after = line.substr(commaPos + 1);
			float number = atof(after.c_str());

			// Store the data in the class's map
			this->data[befor] = number;
		}
	}
}

// Function to check if a date string is valid
int isValidDate(std::string line)
{
	// Check the length and format of the date string
	if (line.length() != 10 || line[4] != '-' || line[7] != '-')
		return 1; // Invalid format

	// Extract and validate the year, month, and day
	if (std::atoi(line.substr(0,4).c_str()) < 2009 || std::atoi(line.substr(0, 4).c_str()) > 2022)
		return 2; // Invalid year

	if (std::atoi(line.substr(5,2).c_str()) < 1 || std::atoi(line.substr(5, 2).c_str()) > 12)
		return 3; // Invalid month

	if (std::atoi(line.substr(8, 2).c_str()) < 1 || std::atoi(line.substr(8, 2).c_str()) > 31)
		return 4; // Invalid day

	// Date is valid
	return 5;
}

// Function to check if a number is valid
int isValidNum(float num)
{
	// Check if the number is negative
	if (num < 0)
		return 2; // Negative number

	// Check if the number is outside a valid range
	if (num < 0 || num > 1000)
		return 3; // Out of range

// Number is valid
	return 1;
}

int BitcoinExchange::check_line(std::string line)
{
	// Initialize variables
	std::string date;
	size_t l;
	std::string num_str;
	float number;
	size_t len_normal;
	int i;

	// Find the position of the first '|' character in the line
	size_t len = line.find('|');
	len_normal = len + 1;

	// Find the position of the first non-space character in the line
	size_t not_newline = line.find_first_not_of(" ");

	// Check if there are non-space characters in the line
	if (not_newline != std::string::npos)
	{
		// Process the date part of the line
		if (len != std::string::npos)
		{
			if (len > 11)
			{
				len--;
				while (len)
				{
					if (line[len] != ' ')
						break;
					len--;
				}
				date = line.substr(0, len + 1 );
			}

			else
				date = line.substr(0, len - 1 );
		}

		else
			date = line.substr(0, len);

		// Process the numerical part of the line, removing extra spaces
		bool inSpaces = false;
		std::string result;

		for (size_t i = len_normal; i < line.size(); i++)
		{
			if (isspace(line[i]))
			{
				if (!inSpaces)
				{
					inSpaces = true;
					result += ' ';  // Add a single space for the sequence of spaces
				}
			}

			else
			{
				inSpaces = false;
				result += line[i];
			}
		}

		// Remove trailing spaces
		if (!result.empty() && result[result.size() - 1] == ' ')
			result.resize(result.size() - 1);

		// Find the position of the first non-space character in the result
		size_t start = result.find_first_not_of(" ");

		// Check if there are non-space characters in the result
		if (start != std::string::npos)
		{
			result = result.substr(start);
			l = 0;
		}

		else
		{
			l = -1;
			result.clear(); // If only spaces are left, clear the string
		}

		// Validate the numerical part of the line
		while (l < result.size())
		{
			if (isdigit(result[l]) || (result[l] == '.' && result[l+1] != '\0') || (result[l] == '-' && result[l+1] != '\0'))
				l++;

			else
				break;
		}

		// If the numerical part is valid, convert it to a float
		if (l == result.size())
		{
			num_str = result;
			number = std::atof(num_str.c_str());
		}

		// Check if both date and numerical parts are valid
		i = isValidDate(date);

		if (i == 5 && l == result.size())
		{
			// Check if the number is positive or within a certain range
			if (isValidNum(number) == 2)
			{
				std::cout << "Error: not a positive number." << std::endl;
				return 0;
			}

			else if (isValidNum(number) == 3)
			{
				std::cout << "Error: too large a number." << std::endl;
				return 0;
			}

			else
				return 1; // Line is valid
		}

		else
		{
			std::cout << "Error: bad input => " << date << std::endl;
			return 0;
		}
	}

	else
		return 0; // Line is empty or contains only spaces
}

void BitcoinExchange::print_all()
{
	// Initialize variables
	std::string line;

	// Define header strings
	std::string header = "date | value";
	std::string inputDate;
	float DataNum;
	float number_input;

	// Clear and reset the file stream to the beginning of the file
	fileStream.clear();
	fileStream.seekg(0, std::ios::beg);

	// Read lines from the input file
	while (std::getline(fileStream, line))
	{
		// Skip the header line
		if (line == header)
			continue;

		// Check if the line is valid using the check_line function
		if (check_line(line))
		{
			// Find the position of the space character in the line
			size_t pipePos = line.find(' ');

			// Check if a space character was found
			if (pipePos != std::string::npos)
			{
				// Extract the input date and numerical value from the line
				inputDate = line.substr(0, pipePos);
				std::string after = line.substr(pipePos + 2);
				number_input = atof(after.c_str());

				// Search for the input date in the data map
				bool found = false;
				std::map<std::string, double>::iterator it;

				for (it = data.begin(); it != data.end(); ++it)
				{
					if (it->first == inputDate)
					{
						found = true;
						DataNum = it->second;
						break;
					}
				}

				// If the input date was found in the map, calculate and print the result
				if (found)
					std::cout << inputDate << "=> " << number_input << " = " << number_input * DataNum << std::endl;

				else
				{
					// If the input date was not found, find the lower bound in the map
					it = data.lower_bound(inputDate);

					// Move the iterator one step back to get the lower bound
					if (it != data.begin())
						--it;

					// Print the result using the lower bound value
					if (it != data.end())
						std::cout << inputDate << "=> " << number_input << " = " << number_input * it->second << std::endl;
				}
			}
		}
	}
}

size_t  BitcoinExchange::size_for_input_file()
{
	// Initialize variables
	std::string ll;
	size_t i = 0;

	// Read lines from the input file and count them to determine the file size
	while (std::getline(fileStream, ll))
		i++;

	// Return the total number of lines (file size)
	return i;
}
