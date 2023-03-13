#include "Array.hpp"

#define MAX_VAL 750

// 42 complex test case available in eval
/*
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}
*/

int main()
{

	Array<int>			intArray;
	Array<std::string>	stringArray(10);
	Array<std::string>	otherStringArray;

	stringArray[0] = "Green";
	stringArray[1] = "Blue";
	stringArray[2] = "Pink";
	stringArray[3] = "Red";
	stringArray[4] = "White";
	stringArray[5] = "Black";
	std::cout << "intArray.size() = " << intArray.Size() << std::endl;
	std::cout << "stringArray.size() = " << stringArray.Size() << std::endl;
	otherStringArray = stringArray;
	otherStringArray[3] = "Color";
	std::cout << stringArray[3] << std::endl;
	std::cout << otherStringArray[3] << std::endl;
	try
	{
		std::cout << stringArray[59] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		std::cout << stringArray[-3] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}
