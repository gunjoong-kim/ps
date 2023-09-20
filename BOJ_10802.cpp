#include <string>
#include <iostream>

int main() {
	int upper, lower, digit, space;

	std::string str;
	while (getline(std::cin, str)) { // getline 리턴값 생각해보기
		upper = 0;
		lower = 0;
		digit = 0;
		space = 0;
		for (char ch : str) {
			if (isupper(ch))
				upper++;
			else if (islower(ch))
				lower++;
			else if (isdigit(ch))
				digit++;
			else if (isspace(ch))
				space++;
		}
		std::cout << lower << ' ' << upper << ' ' << digit << ' ' << space << '\n';
	}
	return 0;
}