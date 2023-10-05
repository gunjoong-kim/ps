#include <iostream>
#include <vector>

void print_goldbach(int num, std::vector<int> &table)
{
	for (int i = 3; i <= num; i = i + 2)
	{
		if (table[i] == 1 && table[num - i] == 1)
		{
			std::cout << num << " = " << i << " + " << num - i << '\n';
			return;
		}
	}
	std::cout << "Goldbach's conjecture is wrong." << '\n';
}

int main()
{
	std::ios_base::sync_with_stdio(false); // improve io speed
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int num;
	std::vector<int> table(1000001, 1);
	table[0] = 0;
	table[1] = 1;

	for(int i = 2; i * i <= 1000001; i++)
	{
		if (table[i] == 1)
		{
			for (int j = i; i * j <= 1000001; j++)
			{
				table[i * j] = 0;
			}
		}
	}

	while(1)
	{
		std::cin >> num;
		if (num == 0)
			break;
		print_goldbach(num, table);
	}

	return 0;
}