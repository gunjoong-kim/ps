#include "Hash.hpp"
#include <iostream>

int main() {
	Hash h;

	h.insert(1, "what");
	h.insert(2, "the");
	h.insert(3, "fuck");
	h.insert(1001, "is that right?");

	h.print_table();

	std::cout << "key 1001 : " << h.search(1001) << std::endl;
	h.remove(1001);
	std::cout << "key 1001 : " << h.search(1001) << std::endl;
}