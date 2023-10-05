#include <stack>
#include <iostream>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	stack<char> st;
	string s;
	bool is_tag = false;
	getline(cin, s);
	s += '\n';

	for (char ch : s) {
		if (is_tag) {
			cout << ch;
			if (ch == '>')
				is_tag = false;
		} else {
			if (ch == '<' || ch == ' ' || ch == '\n') {
				while (!st.empty()) {
					cout << st.top();
					st.pop();
				}
				cout << ch;
				if (ch == '<')
					is_tag = true;
			} else
				st.push(ch);
		}
	}
	return (0);
}