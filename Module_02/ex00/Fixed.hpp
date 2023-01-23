# ifndef FIXED_POINT
# define FIXED_POINT

#include <iostream>

class Fixed
{
	private:
		int fixed_point_val;
		static const int fractional_bits = 8;

	public:
		Fixed();
		Fixed(Fixed& fix);
		Fixed& operator = (Fixed& cpy);
		~Fixed();
		int getRawBits(void) const;
		void setRawBits(int const raw);
};

# endif
