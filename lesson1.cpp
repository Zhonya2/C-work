#include <iostream>
using namespace std;
int main()
{

    const int SIZE = 10;
    int arr[10];

    for(int index = 0; index < 20; index++)
        arr[index] = index + index;

    for (int index = 0; index < 10; index++)
        cout << "arr[" << index << "] = " << arr[index] << endl;

    return 0;
}