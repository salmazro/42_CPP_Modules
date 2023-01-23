#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->fixed_point_val = 0;
}

Fixed::Fixed(Fixed& fix)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fix;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" <<std::endl;
}

Fixed& Fixed::operator = (Fixed& cpy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->fixed_point_val = cpy.getRawBits();
	return (*this);
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->fixed_point_val);
}

void	Fixed::setRawBits(int const raw)
{
	this->fixed_point_val = raw;
}
