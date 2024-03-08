// Hasher.cpp: plik źródłowy dla elementu docelowego.
//

#include "../HashFunc/HashFunc.h"

#include <iostream>
#include <iomanip>
#include <sstream>

using std::string;

constexpr size_t inlen(size_t len) {
	return len + (63 - (len%63));
}

int main()
{
	string input;
	string key;
	std::cin >> input >> key;
	sponge_state state;
	init_sponge(&state, reinterpret_cast<uint8_t*>(&key[0]), key.size());
	const size_t inSize = inlen(input.size());
	uint8_t* s = (uint8_t*)calloc(inSize,sizeof(uint8_t));
	memcpy(s, input.c_str(), input.size());
	for (int i = 0; i < inSize; i += 63) absorb(&state, &s[i]);
	std::stringstream ss;
	ss << std::hex;
	for (int i = 0; i < 84; i++) ss << std::setw(2) << std::setfill('0') << (int)squeeze(&state);
	std::cout << ss.str() << std::endl;
	free(s);
	system("pause");
	return 0;
}
