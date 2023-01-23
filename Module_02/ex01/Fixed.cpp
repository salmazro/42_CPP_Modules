#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->fixed_point_val = 0;
}

Fixed::Fixed(const Fixed& fix)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fix;
}

Fixed::Fixed(const int i)
{
	std::cout << "Int constructor called" << std::endl;
	setRawBits(i << this->fractional_bits);
}

Fixed::Fixed(const float f)
{
	std::cout << "Float constructor called" << std::endl;
	setRawBits((int)(roundf(f * ( 1 << this->fractional_bits))));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" <<std::endl;
}

Fixed& Fixed::operator = (const Fixed& cpy)
{
	std::cout << "Copy assignment operator called" <<std::endl;
	if (this != &cpy)
		this->fixed_point_val = cpy.getRawBits();
	return (*this);
}

int Fixed::getRawBits( void ) const
{
	return (this->fixed_point_val);
}

void Fixed::setRawBits( int const raw )
{
	this->fixed_point_val = raw;
}

float Fixed::toFloat( void ) const
{
	return ((float)this->getRawBits() / (1 <<fractional_bits));
}

int Fixed::toInt( void ) const
{
	return(this->getRawBits() >> this->fractional_bits);
}

std::ostream& operator<<(std::ostream& out, Fixed const& fixe)
{
	out <<  fixe.toFloat();
	return(out);
}
