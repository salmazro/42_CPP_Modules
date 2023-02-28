#include "Serializer.hpp"

int main(int ac, char **argv)
{
	Data *data = new Data;
	Data *deSerData;
	uintptr_t ser;

	if (ac != 2)
		std::cout << "Error: invalid argument" << std::endl;
	else
	{
		data->info = "Updated: 2022/12/18 03:50:12 by ";
		std::cout << "Original data     : " << data->info << argv[1] << std::endl;
		ser = serialize(data);
		std::cout << "Serialized data   : " << ser << std::endl;
		deSerData = deserialize(ser);
		std::cout << "Deseerialized data: " << deSerData->info <<  argv[1] << std::endl;
		delete data;
	}
	return 0;
}
