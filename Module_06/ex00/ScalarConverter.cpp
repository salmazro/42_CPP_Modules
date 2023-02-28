#include "ScalarConverter.hpp"


ScalarConverter::ScalarConverter() : storage(NULL), arg(NULL), chare(0), num_int(0), num_float(0), num_double(0)
{

}

ScalarConverter::ScalarConverter(char *store)
{
    this->storage = store;
    this->arg = store;
    try {
    this->convert();
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}

ScalarConverter::ScalarConverter(ScalarConverter &copy)
{
    *this = copy;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter &source)
{
    if(this != &source)
    {
        this->arg = source.arg;
        this->storage = source.storage;
        this->chare = source.chare;
        this->num_int = source.num_int;
        this->num_float = source.num_float;
        this->num_double = source.num_double;
    }
    return (*this);
}

ScalarConverter::~ScalarConverter()
{

}

void ScalarConverter::convert()
{
    if ((this->storage.length() == 1) && (this->storage[0] < '0' || this->storage[0] > '9'))
    {
        this->chare = this->storage[0];
        this->num_int = static_cast<int>(storage[0]);
        this->num_float = static_cast<float>(storage[0]);
        this->num_double = static_cast<double>(storage[0]);
    }
    else if (is_number() || this->storage == "nan" || this->storage == "nanf" || this->storage == "impossible" || this->storage == "inff"
                || this->storage == "-inf" || this->storage == "+inf" || this->storage == "+nanf" || this->storage == "-nanf" )
    {
        this->chare = static_cast<char>(strtod(arg , 0));
        this->num_int = static_cast<int>(strtod(arg , 0));
        this->num_float = static_cast<float>(strtod(arg , 0));
        this->num_double = static_cast<double>(strtod(arg , 0));
    }
    else
        throw std::invalid_argument("invalid arguments taken");
}

void ScalarConverter::printToChar() const
{
    std::cout << "char: ";
    if(std::isnan(num_double) || std::isinf(num_double))
        std::cout << "impossible" << std::endl;
    else if(isprint(this->chare) == 0 )
        std::cout << "Non displayable" <<std::endl;
    else
        std::cout << this->chare << std::endl;
}

void ScalarConverter::printToInt() const
{
    std::cout << "int: ";
    if(std::isnan(num_double) || std::isinf(num_double))
        std::cout << "impossible" << std::endl;
    else
        std::cout << this->num_int <<std::endl;
}

void ScalarConverter::printToFloat() const
{
    std::cout << "float: " << this->num_float;
    if (this->num_float - this->num_int == 0)
        std::cout << ".0";
    std::cout << "f" << std::endl;
}

void ScalarConverter::printToDouble() const
{
    std::cout << "double: " <<this->num_double;
    if (this->num_double - this->num_int == 0)
        std::cout << ".0";
    std::cout << std::endl;
}

void ScalarConverter::printter() const
{
    this->printToChar();
    this->printToInt();
    this->printToFloat();
    this->printToDouble();
}

bool	ScalarConverter::is_number(void) const
{
	std::string s = this->arg;
	std::string::iterator	i = s.begin();
	while (std::isdigit(*i) && i != s.end())
		++i;
	if (*i == '.' && i != s.end())
	{
		++i;
		while (std::isdigit(*i) && i != s.end())
			++i;
		if (*i == 'f' && i != s.end())
			++i;
	}
	return (i == s.end() && *--i != '.' && !s.empty());
}
