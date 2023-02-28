#include "base.hpp"

int main(void)
{
	srand(time(NULL));
	Base*	p;
	p = generate();
	identify(p);
	identify(*p);
    return (0);
}
