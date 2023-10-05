#include <iostream>
#include <stack>
#include <vector>

int main() {
	int n;
	int input;

	std::cin >> n;
	std::vector<int> freq(1000000, 0);
	std::vector<int> inputs(n, 0);
	std::vector<int> answer(n, -1);
	for (int i = 0; i < n; i++) {
		std::cin >> inputs[i];
		freq[inputs[i]]++;
	}

	std::stack<int> st;
	for (int i = 0; i < n; i++) {
		while (!st.empty() && freq[inputs[st.top()]] < freq[inputs[i]]) {
			answer[st.top()] = inputs[i];
			st.pop();
		}
		st.push(i);
	}

	for (int i = 0; i < n - 1; i++) {
		std::cout << answer[i] << ' ';
	}
	std::cout << answer[n - 1] << '\n';
	return (0);
}