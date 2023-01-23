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

		int operator==(const Fixed& val)const;
        int operator!=(const Fixed& val)const;
        int operator>=(const Fixed& val)const;
        int operator<=(const Fixed& val)const;
        int operator<(const Fixed& val)const;
        int operator>(const Fixed& val)const;

		Fixed operator+(const Fixed& val)const;
        Fixed operator-(const Fixed& val)const;
        Fixed operator*(const Fixed& val)const;
        Fixed operator/(const Fixed& val)const;

		Fixed& operator++(void);
        Fixed& operator--(void);
        Fixed operator++(int);
        Fixed operator--(int);

		static Fixed& min(Fixed& val1, Fixed& val2);
        static Fixed& max(Fixed& val1, Fixed& val2);
        static const Fixed& min(const Fixed& val1, const Fixed& val2);
        static const Fixed& max(const Fixed& val1, const Fixed& val2);

};

std::ostream& operator<<(std::ostream& out, Fixed const& fixe);

# endif
