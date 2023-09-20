#include <string>
#include <iostream>

int main() {
	int a,b,c,d;
	long long ab, cd;

	std::cin >> a >> b >> c >> d;
	ab = std::stoll(std::to_string(a) + std::to_string(b));
	cd = std::stoll(std::to_string(c) + std::to_string(d));
	std::cout << ab + cd << '\n';
	return 0;
}