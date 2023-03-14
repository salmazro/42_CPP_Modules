#include "Span.hpp"

Span::Span() : leng(0)
{

}

Span::Span(int unsigned n) : leng(n)
{

}

Span::Span(const Span &copy)
{
    *this = copy;
}

Span const &Span::operator=(const Span &source)
{
    if(&source != this)
    {
        this->vect = source.vect;
        this->leng = source.leng;
    }
    return(*this);
}

unsigned int Span::getSize(void)const
{
	return (this->vect.size());
}

unsigned int Span::getCapacity(void) const
{
    return (this->leng);
}

int	getSpan(const int upper, const int lower)
{
	return (upper - lower);
}

Span::~Span()
{

}

void Span::addNumber(int numero)
{
    if (this->vect.size() >= this->leng)
        throw std::logic_error("Capicty Limit Error");
    else
        vect.push_back(numero);
}

void Span::numberGenerator()
{
    int remaining = this->leng - getSize();
    for (int i = 0; i < remaining; i++)
        addNumber(rand() % 87 + 1);
}


int Span::shortestSpan() const
{

    if (vect.size() > 1)
    {
        std::vector<int> sorted_number(vect);
        int min_span = INT_MAX;
        std::sort(sorted_number.begin(), sorted_number.end());
        for (unsigned long i = 1; i < sorted_number.size(); i++)
        {
            int span = getSpan(sorted_number[i], sorted_number[i - 1]);
            if (min_span > span)
                min_span = span;
        }
        return min_span;
    }
    throw std::logic_error("Error: wrong size.");
}



int Span::longestSpan() const
{
	if (this->vect.size() > 1)
	{
		return (*std::max_element(this->vect.begin(), this->vect.end()) - *std::min_element(this->vect.begin(), this->vect.end()));
	}
	throw std::logic_error("Error: wrong size.");
}
