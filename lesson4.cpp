#include <iostream>
using namespace std;

void Show(const int arr[], const int size)
{
    if(size <= 0)
    {
        cout << "Error\n";
        return;
    }

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << "";
    }
    cout << endl;
}

void Initialize(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = i + i;
    }
}

int main() {
    const int SIZE1 = 3;
    const int SIZE2 = 5;

    int arr1[SIZE1];
    int arr2[SIZE2];

    Show(arr1, SIZE1);
    Show(arr2, SIZE2);

    return 0;
}
