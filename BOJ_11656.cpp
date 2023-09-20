#include <algorithm>
#include <vector>
#include <iostream>
#include <string>

int main() {
	std::string str;
	getline(std::cin, str);
	std::vector<std::string> suffix(str.length(), "");

	for (int i = 0; i < str.length(); i++) {
		suffix[i] = str.substr(i, str.npos);
	}
	std::sort(suffix.begin(), suffix.end());
	for (int i = 0; i < str.length(); i++)
		std::cout << suffix[i] << '\n';
	return 0;
}

// 이게 뭐람....
// #include <iostream>
// #include <string>
// #include <cstring>
// #include <algorithm>
// #include <vector>
// using namespace std;
// int main() {
//     string s;
//     cin>>s;
//     int n = s.size();
//     vector<int> a;
//     for (int i=0; i<n; i++) a.push_back(i);
//     sort(a.begin(),a.end(), [&s](int u, int v) {
//         return strcmp(s.c_str()+u,s.c_str()+v) < 0;
//     });
//     for (auto &x : a) {
//         cout << s.substr(x) << '\n';
//     }
//     return 0;
// }