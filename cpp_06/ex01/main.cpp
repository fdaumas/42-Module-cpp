#include "Serialization.hpp"

int main() {
	Data data;

	data.int_a = 10;
	data.int_b = 42;
	data.string_c = "Serialize Done";

	uintptr_t raw = serialize(&data);
	Data* cp_data = deserialize(raw);
	std::cout << cp_data->int_a << " " << cp_data->int_b << " "
		<< cp_data->string_c << std::endl;
	return (0);
}