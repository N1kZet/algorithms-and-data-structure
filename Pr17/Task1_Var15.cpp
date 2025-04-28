#include <iostream>
#include <stack>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    srand(time(0));


    stack<int> originalStack;
    for (int i = 0; i < 10; ++i)
    {
        int num = rand() % 101 - 50;
        originalStack.push(num);
    }

    cout << "Исходный стек (первый элемент - вершина стека):" << endl;
    stack<int> temp = originalStack;
    while (!temp.empty())
    {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;

    size_t size = originalStack.size();
    size_t halfSize = size / 2;

    stack<int> tempStack;
    for (size_t i = 0; i < halfSize; ++i)
    {
        tempStack.push(originalStack.top());
        originalStack.pop();
    }

    stack<int> newStack;
    while (!originalStack.empty())
    {
        newStack.push(originalStack.top());
        originalStack.pop();
    }

    cout << "Новый стек (вторая половина исходного стека):" << endl;
    while (!newStack.empty())
    {
        cout << newStack.top() << " ";
        newStack.pop();
    }
    cout << endl;

    return 0;
}
