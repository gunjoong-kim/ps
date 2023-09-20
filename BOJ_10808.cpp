#include <iostream>
#include <vector>
#include <string>

int main() {
	std::string str;
	std::vector<int> freq(26, 0);

	getline(std::cin, str);
	for (char ch : str) {
		freq[ch - 'a']++;
	}
	for (int i = 0; i < 25; i++)
		std::cout << freq[i] << ' ';
	std::cout << freq[25] << '\n';
	return 0;
}

// 조금더 c++의 여러가지 라이브러리를 이용한 코드
// #include <algorithm>
// #include <iostream>
// #include <string>
// using namespace std;
// int main() {
//     string s;
//     cin >> s;

//     for (int i='a'; i<='z'; i++) {
//         cout << count(s.begin(), s.end(), i) << ' ';
//     }

//     cout << '\n';
    

//     return 0;
// }