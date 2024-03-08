// Hasher.cpp: plik źródłowy dla elementu docelowego.
//

#include "../HashFunc/HashFunc.h"

#include <iostream>
#include <iomanip>
#include <sstream>

using std::string;


int main()
{
	uint8_t hsh[63];
	string input;
	std::cin >> input;
	hash(reinterpret_cast<uint8_t*>(&input[0]), input.size(), hsh);
	std::stringstream ss;
	ss << std::hex;
	for (int i = 0; i < 63; i++) ss << std::setw(2) << std::setfill('0') << (int)hsh[i];
	std::cout << ss.str() << std::endl;
	system("pause");
	return 0;
}
