#include "Fixed.hpp"

Fixed::Fixed()
{
	this->fixed_point_val = 0;
}

Fixed::Fixed(const Fixed& fix)
{
	*this = fix;
}

Fixed::Fixed(const int i)
{
	setRawBits(i << this->fractional_bits);
}

Fixed::Fixed(const float f)
{
	setRawBits((int)(roundf(f * ( 1 << this->fractional_bits))));
}

Fixed::~Fixed()
{
}

Fixed& Fixed::operator = (const Fixed& cpy)
{
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

int Fixed::operator==(const Fixed& val)const
{
	if (this->fixed_point_val == val.fixed_point_val)
		return (1);
	return (0);
}

int Fixed::operator!=(const Fixed& val)const
{
	if (this->fixed_point_val != val.fixed_point_val)
		return (1);
	return (0);
}

int Fixed::operator>=(const Fixed& val)const
{
	if (this->fixed_point_val >= val.fixed_point_val)
		return (1);
	return (0);
}

int Fixed::operator<=(const Fixed& val)const
{
	if (this->fixed_point_val <= val.fixed_point_val)
		return (1);
	return (0);
}

int Fixed::operator<(const Fixed& val)const
{
	if (this->fixed_point_val < val.fixed_point_val)
		return (1);
	return (0);
}

int Fixed::operator>(const Fixed& val)const
{
	if (this->fixed_point_val > val.fixed_point_val)
		return (1);
	return (0);
}

Fixed Fixed::operator+(const Fixed& val)const
{
	Fixed res;
	res.setRawBits(this->fixed_point_val + val.fixed_point_val);
	return(res);
}

Fixed Fixed::operator-(const Fixed& val)const
{
	Fixed res;
	res.setRawBits(this->fixed_point_val - val.fixed_point_val);
	return(res);
}

Fixed Fixed::operator*(const Fixed& val)const
{
	Fixed res;
	res.setRawBits((this->fixed_point_val * val.fixed_point_val) / (1 << fractional_bits));
	return(res);
}

Fixed Fixed::operator/(const Fixed& val)const
{
	Fixed res;
	res.setRawBits((this->fixed_point_val / val.fixed_point_val) / (1 << fractional_bits));
	return(res);
}

Fixed& Fixed::operator++(void)
{
	this->fixed_point_val++;
	return(*this);
}

Fixed& Fixed::operator--(void)
{
	this->fixed_point_val--;
	return(*this);
}

Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	++(*this);
	return temp;
}

Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	--(*this);
	return temp;
}

Fixed& Fixed::min(Fixed& val1, Fixed& val2)
{
	if(val1 < val2)
		return (val1);
	return (val2);
}

Fixed& Fixed::max(Fixed& val1, Fixed& val2)
{
	if(val1 > val2)
		return (val1);
	return (val2);
}

const Fixed& Fixed::min(const Fixed& val1, const Fixed& val2)
{
	if(val1 < val2)
		return (val1);
	else
		return (val2);
}

const Fixed& Fixed::max(const Fixed& val1, const Fixed& val2)
{
	if(val1 > val2)
		return (val1);
	else
		return (val2);
}

std::ostream& operator<<(std::ostream& out, Fixed const& fixe)
{
	out <<  fixe.toFloat();
	return(out);
}
