#include <iostream>
#include <stack>
#include <string>

int priority(char ch) {
	if (ch == '(' || ch == ')')
		return 0;
	else if (ch == '-' || ch == '+')
		return 1;
	else if (ch == '*' || ch == '/')
		return 2;
	return 3;
}

bool is_operator(char ch) {
	if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '(' || ch == ')')
		return true;
	return false;
}

int main() {
	std::stack<char> st;
	std::string midfix;
	getline(std::cin, midfix);
	for(char ch : midfix) {
		if (!is_operator(ch))
			std::cout << ch;
		else {
			if (ch == ')') {
				while (st.top() != '(') {
					std::cout << st.top();
					st.pop();
				}
				st.pop();
			} else if (ch == '(')
				st.push(ch);
			else if (!st.empty() && (priority(st.top()) >= priority(ch))) {
				while (!st.empty() && st.top() != '(' && (priority(st.top()) >= priority(ch))) {
					std::cout << st.top();
					st.pop();
				}
				st.push(ch);
			} else
				st.push(ch);
		}
	}
	while (!st.empty()) {
		std::cout << st.top();
		st.pop();
	}
	std::cout << '\n';
	return (0);
}