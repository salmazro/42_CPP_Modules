#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include "iostream"
#include <cmath>
#include <cstring>
#include <limits>
#include <exception>

class ScalarConverter
{
    private:
        std::string storage;
        char *arg;
        char chare;
        int num_int;
        float num_float;
        double num_double;

    public:
        ScalarConverter(); // Default Constructor
        ScalarConverter(char *store); // Field Constructor
        ScalarConverter(ScalarConverter &copy); // Copy Constructor
        ScalarConverter &operator=(ScalarConverter &source); // Copy Assignement Operator
        ~ScalarConverter(); // Destructor

        void convert();
        void printToChar() const;
        void printToInt() const;
        void printToFloat() const;
        void printToDouble() const;
        bool is_number(void) const;
        void printter() const;
};

#endif
