#include <iostream>
#include <vector>

bool is_prime(int n)
{
	if (n == 1)
		return false;
	for (int i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}

int main()
{
	int n;
	std::cin >> n;
	
	int prime;
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		std::cin >> prime;
		if (is_prime(prime))
			cnt++;
	}
	std::cout << cnt << '\n';
	return 0;
}