#include <iostream>
#include <vector>

int main()
{
	int min, max;
	std::cin >> min >> max;

	std::vector<bool> prime(max + 1, true);
	prime[0] = false;
	prime[1] = false;
	for (int i = 2; i * i <= max; i++)
	{
		if (prime[i] == true)
		{
			for (int j = i; j * i <= max; j++)
				prime[j * i] = false;
		}
	}
	for (int i = min; i <= max; i++)
	{
		if (prime[i] == true)
			std::cout << i << '\n';
	}
	return 0;
}