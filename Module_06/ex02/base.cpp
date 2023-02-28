#include  "base.hpp"

/*

The code defines a function generate() which returns a pointer to an object of type Base, which is a base class.

 The function uses an enumeration RandomType with three enumerators: A, B, and C. It initializes the random number generator with the current time,

 and uses the rand() function to generate a random number between 0 and 2 (inclusive).

Based on the generated random number, the function assigns the corresponding enumerator value to the variable randomType.

Then, it uses an if-else statement to check the value of randomType and return a new object of the corresponding derived class: A, B, or C.

The new operator creates a new object and returns a pointer to the object, which is then returned by the function.

This function allows for a random object of a derived class to be generated and returned at runtime, making the code more dynamic.

*/

Base* generate(void)
{
    int randomType;
    srand(time(NULL));
    randomType = rand() % 3;
    if (randomType == 1)
        return (new A);
    else if (randomType == 2)
        return (new B);
    else
        return (new C);
}

void identify(Base* p)
{
    A *a;
    if ((a = dynamic_cast<A *>(p)) != NULL)
        std::cout << "A" <<std::endl;
    B *b;
    if ((b = dynamic_cast<B *>(p)) != NULL)
        std::cout << "B" << std::endl;
    C *c;
    if ((c = dynamic_cast<C *>(p)) != NULL)
        std::cout << "C" << std::endl;
}

void identify(Base& p)
{
    try{
        A& a = dynamic_cast<A &> (p);
        (void)a;
        std::cout << "A" << std::endl;
    }catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    try{
        B& b = dynamic_cast<B &> (p);
        (void)b;
        std::cout << "B" << std::endl;
    }catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
     try{
        C& c = dynamic_cast<C &> (p);
        (void)c;
        std::cout << "C" << std::endl;
    }catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}
