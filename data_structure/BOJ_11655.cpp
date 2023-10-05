#include <string>
#include <iostream>

int main() {
	std::string str;

	getline(std::cin, str);
	for (int i = 0; i < str.length(); i++) {
		if (islower(str[i]))
			str[i] = (str[i] - 'a' + 13) % 26 + 'a';
		else if (isupper(str[i]))
			str[i] = (str[i] - 'A' + 13) % 26 + 'A';
	}
	std::cout << str << '\n';
	return 0;
}