#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	stack<char> st;
	string s;
	char prev = ')';
	int cnt = 0;

	getline(cin, s);
	for (char ch : s) {
		if (ch == '(')
			st.push(ch);
		else {
			st.pop();
			if (prev == '(')
				cnt += st.size();
			else
				cnt++;
		}
		prev = ch;
	}
	cout << cnt << '\n';
	return (0);
}