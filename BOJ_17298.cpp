#include <iostream>
#include <stack>

int main()
{
    int n, input;
    std::stack<int> left;
    std::stack<int> right;
    std::stack<int> output;

    std::cin >> n;

    for (int i = 0; i < n; i++)
    {
        std::cin >> input;
        left.push(input);
    }

    right.push(left.top());
    left.pop();
    output.push(-1);

    for (int i = 0; i < n - 1; i++)
    {
        while (!right.empty() && right.top() <= left.top())
            right.pop(); //이후에도 pop된 것들은 의미가 없음 이미 왼쪽 원소들에대해 가장 큰 가능성을 가지고 있는 원소는 이 pop된 값들보다 크므로
        if (right.empty())
            output.push(-1);
        else
            output.push(right.top());
        right.push(left.top());
        left.pop();
    }

    for (int i = 0; i < n - 1; i++)
    {
        std::cout << output.top() << " ";
        output.pop();
    }
    std::cout << output.top() << std::endl;
}
