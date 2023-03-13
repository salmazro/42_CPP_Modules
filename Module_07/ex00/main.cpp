#include "whatever.hpp"

// int main()
// {
// 	int a = 21;
// 	int b = 54;
// 	std::cout << "the old a =>" << a <<std::endl;
// 	std::cout << "the old b =>" << b <<std::endl;
// 	::swap<int>(a,b);
// 	std::cout << "the new a =>" << a <<std::endl;
// 	std::cout << "the new b =>" << b <<std::endl;

// 	float d = 32.21;
// 	float e = 324.54;
// 	std::cout << "the old d =>" << d <<std::endl;
// 	std::cout << "the old e =>" << e <<std::endl;
// 	::swap<float>(d,e);
// 	std::cout << "the new d =>" << d <<std::endl;
// 	std::cout << "the new e =>" << e <<std::endl;


// 	int q = 21;
// 	int w = 54;
// 	double r = 100.21;
// 	double t = 42.21;
// 	std::cout << "max for int " << ::max<int>(q,w) << std::endl;
// 	std::cout << "max for double " << ::max<double>(r,t) << std::endl;
// 	std::cout << "min for int " << ::min<int>(q,w) << std::endl;
// 	std::cout << "min for double " << ::min<double>(r,t) << std::endl;
// }


// 42 complex test case available eval
/*
class Awesome
{
  public:
    Awesome(void) : _n(0) {}
    Awesome( int n ) : _n( n ) {}
    Awesome & operator= (Awesome & a) { _n = a._n; return *this; }
    bool operator==( Awesome const & rhs ) const { return (this->_n == rhs._n); }
    bool operator!=( Awesome const & rhs ) const{ return (this->_n != rhs._n); }
    bool operator>( Awesome const & rhs ) const { return (this->_n > rhs._n); }
    bool operator<( Awesome const & rhs ) const { return (this->_n < rhs._n); }
    bool operator>=( Awesome const & rhs ) const { return (this->_n >= rhs._n); }
    bool operator<=( Awesome const & rhs ) const { return (this->_n <= rhs._n); }
    int get_n() const { return _n; }
  private:
    int _n;
};
std::ostream & operator<<(std::ostream & o, const Awesome &a) { o << a.get_n(); return o; }

int main(void)
{
	Awesome a(2), b(4);

        swap(a, b);
        std::cout << a << " " << b << std::endl;
        std::cout << max(a, b) << std::endl;
        std::cout << min(a, b) << std::endl;
        return (0);
}
*/


// 42 int main available in subject
int main(void)
{
	int a = 2;
	int b = 3;

	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";

	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
}


