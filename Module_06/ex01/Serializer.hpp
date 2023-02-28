#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <string>

typedef struct s_data
{
	std::string info;
} Data;

Data* deserialize(uintptr_t raw);

uintptr_t serialize(Data* ptr);

#endif
