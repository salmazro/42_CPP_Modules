# ifndef FIXED_POINT
# define FIXED_POINT

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int fixed_point_val;
		static const int fractional_bits = 8;

	public:
		Fixed();
		Fixed(const Fixed& fix);
		Fixed(const int i);
		Fixed(const float f);
		~Fixed();
		Fixed& operator = (const Fixed& cpy);
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;
};

std::ostream& operator<<(std::ostream& out, Fixed const& fixe);

# endif
