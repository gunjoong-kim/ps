// Hash in STL
#include <iostream>
#include <map>
#include <string>

int main() {
	std::map <int, std::string> m;

	m.insert(std::make_pair(1, "one"));
	m.insert(std::make_pair(2, "two"));
	m.insert(std::make_pair(3, "three"));
	m.insert(std::make_pair(4, "four"));

	for (auto i = m.begin(); i != m.end(); i++) {
		std::cout << i->first << " " << i->second << std::endl;
	}
}
