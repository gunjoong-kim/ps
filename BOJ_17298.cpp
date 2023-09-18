#include <iostream>
#include <stack>
#include <vector>

int main() {
    int n;
    std::stack<int> st;

    std::cin >> n;
    std::vector<int> inputs(n);
    std::vector<int> answer(n);
    for (int i = 0; i < n; i++)
        std::cin >> inputs[i];

    for (int i = 0; i < n; i++) {
        while (!st.empty() && inputs[st.top()] < inputs[i]) {
            answer[st.top()] = inputs[i];
            st.pop();
        }
        st.push(i);
    }
    while (!st.empty()) {
        answer[st.top()] = -1;
        st.pop();
    }
    for (int i = 0; i < n - 1; i++)
        std::cout << answer[i] << ' ';
    std::cout << answer[n - 1] << '\n';
    return (0);
}

// #include <iostream>
// #include <stack>

// int main()
// {
//     int n, input;
//     std::stack<int> left;
//     std::stack<int> right;
//     std::stack<int> output;

//     std::cin >> n;

//     for (int i = 0; i < n; i++)
//     {
//         std::cin >> input;
//         left.push(input);
//     }

//     right.push(left.top());
//     left.pop();
//     output.push(-1);

//     for (int i = 0; i < n - 1; i++)
//     {
//         while (!right.empty() && right.top() <= left.top())
//             right.pop();
//         if (right.empty())
//             output.push(-1);
//         else
//             output.push(right.top());
//         right.push(left.top());
//         left.pop();
//     }

//     for (int i = 0; i < n - 1; i++)
//     {
//         std::cout << output.top() << " ";
//         output.pop();
//     }
//     std::cout << output.top() << std::endl;
// }
