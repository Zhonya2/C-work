#include <vector>
#include <list>
#include <forward_list>
#include <deque>
#include <array>
#include <stack>

using namespace std;

std::stack<int> numbers;

for (int number = 0; number < 10; number++)
{
    numbers.push(number);
}

size_t initialSize = number.size();
for (size_t i = 0; i < initialSize; i++)
{
    int value = numbers.top();
    numbers.pop();
    cout << value << "";
}
cout << endl;

if(numbers.empty())
{
    cout << "Stack is empty\n";
}
