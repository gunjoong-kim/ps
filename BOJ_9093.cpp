#include <iostream>
#include <stack>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); // improve io speed
	cin.tie(nullptr);
	cout.tie(nullptr);

	stack<char> st;
	int t;
	
	cin >> t;
	cin.ignore();
	while (t--) {
		string s;
		getline(cin, s);
		s += '\n'; // to indicate last word
		for (char ch : s) {
			if (ch == ' ' || ch == '\n') { // if ch is space or newline
				while (!st.empty()) {
					cout << st.top();
					st.pop();
				}
				cout << ch;
			}
			else
				st.push(ch);
		}
	}
	return (0);
}