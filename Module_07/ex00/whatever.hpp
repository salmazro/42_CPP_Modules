#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template <typename T> void swap(T &num1, T &num2)
{
	T temp;

	temp = num1;
	num1 = num2;
	num2 = temp;
}

template <typename T> T max (T &num1, T &num2)
{
	return (num1 > num2) ? num1 : num2;
}

template <typename T> T min (T &num1, T &num2)
{
	return (num1 < num2) ? num1 : num2;
}

#endif
