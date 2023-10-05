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
			for (int j = i; j * i <= max; j++) // 제곱부터 부터 살펴보는것이 옳음 3을 기준으로 3 * 2는 이미 2의 케이스에서 없어짐
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