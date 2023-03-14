#ifndef SPAN_HPP
#define SPAN_HPP

# include <iostream>
#include <climits>
# include <exception>
# include <cstdlib>
# include <time.h>
# include <vector>
# include <algorithm>

class Span
{
    private:
        std::vector<int> vect;
        unsigned int leng;

    public:
        Span();
        Span(int unsigned n);
        Span(const Span &copy);
        Span const &operator=(const Span &source);
        ~Span();

        unsigned int getSize(void) const;
        unsigned int getCapacity(void) const;

        void addNumber(int num);
        void numberGenerator();
        int shortestSpan() const;
        int longestSpan() const;
};

int	getSpan(const int upper, const int lower);

#endif
