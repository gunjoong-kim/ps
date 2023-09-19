#include <stack>
#include <iostream>
#include <string>
#include <vector>

int main() {
	int n;
	std::string operation;
	std::stack<double> st;

	std::cout << std::fixed;
	std::cout.precision(2);

	std::cin >> n;
	std::cin.ignore();
	getline(std::cin, operation);
	std::vector<int> num(n, 0);
	for (int i = 0; i < n; i++)
		std::cin >> num[i];

	for (char ch : operation) {
		double a, b, tmp;
		if (ch == '*' || ch == '/' || ch == '+' || ch == '-') {
			b = st.top();
			st.pop();
			a = st.top();
			st.pop();
			if (ch == '*')
				tmp = a * b;
			else if (ch == '/')
				tmp = a / b;
			else if (ch == '+')
				tmp = a + b;
			else if (ch == '-')
				tmp = a - b;
			st.push(tmp);
		} else
			st.push(num[ch - 'A']);
	}
	std::cout << st.top() << '\n';
	return (0);
}