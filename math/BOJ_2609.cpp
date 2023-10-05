#include <iostream>

int main()
{
	int a, b;
	int a_tmp, b_tmp, tmp;
	std::cin >> a >> b;
	b_tmp = b;
	a_tmp = a;
	while (b_tmp != 0)
	{
		tmp = a_tmp % b_tmp;
		a_tmp = b_tmp;
		b_tmp = tmp;
	}
	std::cout << a_tmp << '\n';
	std::cout << a_tmp * (a / a_tmp) * (b / a_tmp) << '\n';
}