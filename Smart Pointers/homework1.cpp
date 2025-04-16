#include <iostream>
using namespace std;
unique_ptr<int[]> CreateArray()
{
    cout << "Enter size of array:";
    size_t size;
    cin >> size;

    unique_ptr<int[]> arr(new int[size]);
    return arr;
}
int main()
{
    unique_ptr<int[]> ptr1{CreateArray()};

    return 0;
}