/*
BOJ 1643번
title : 1로 만들기
분료 : dp
*/

#include <iostream>
#include <vector>

int dp_rec(std::vector<int> &d, int n)
{
	if (n == 1)
		return 0;
	int answer;
	int tmp;

	if (d[n - 1] != 0)
		answer = d[n - 1];
	else
		answer = dp_rec(d, n - 1);
	if (n % 3 == 0)
	{
		if (d[n / 3] != 0)
			tmp = d[n / 3];
		else
			tmp = dp_rec(d, n / 3);
		answer = std::min(answer, tmp);
	}
	if (n % 2 == 0)
	{
		if (d[n / 2] != 0)
			tmp = d[n / 2];
		else
			tmp = dp_rec(d, n / 2);
		answer = std::min(answer, tmp);
	}
	d[n] = answer + 1;
	return d[n];
}

int main()
{
	int n;
	std::cin >> n;
	std::vector<int> save(n + 1, 0);
	
	for (int i = 2; i <= n; i++)
	{
		save[i] = save[i - 1] + 1;
		if (i % 2 == 0)
			save[i] = std::min(save[i], save[i / 2] + 1);
		if (i % 3 == 0)
			save[i] = std::min(save[i], save[i / 3] + 1);
	}
	std::cout << save[n] << '\n';
	return 0;
}

//int main()
//{
//	int n;
//	std::cin >> n;
//	std::vector<int> d(n + 1, 0);
//	d[0] = 0;
//	d[1] = 0;
//	std::cout << dp_rec(d, n) << '\n';
//	return 0;
//}