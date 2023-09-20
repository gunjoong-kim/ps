#include <vector>
#include <iostream>
#include <string>

int main() {
	std::vector<int> loc(26, -1);
	std::string str;

	getline(std::cin, str);
	
	for(int i = 0; i < str.length(); i++) {
		if (loc[str[i] - 'a'] == -1)
			loc[str[i] - 'a'] = i;
	}
	for (int i = 0; i < 25; i++)
		std::cout << loc[i] << ' ';
	std::cout << loc[25] << '\n';
	return 0;
}

// 조금 더 c++ 라이브러리를 이용한 코드
// #include <algorithm>
// #include <iostream>
// #include <string>
// using namespace std;
// int main() {
//     string s;
//     cin >> s;

//     for (int i='a'; i<='z'; i++) {
//         auto it = find(s.begin(), s.end(), i);
//         if (it == s.end()) {
//             cout << -1 << ' ';
//         } else {
//             cout << (it - s.begin()) << ' ';
//         }
//     }

//     cout << '\n';
    

//     return 0;
// }