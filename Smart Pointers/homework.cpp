#include <iostream>
using namespace std;
int main()
{
    unique_ptr<int> ptr1{new int{10}};
    unique_ptr<int> ptr2{new int{20}};

    cout << "ptr1 points to" << ptr1.get() << endl;
    cout << "ptr1 points to" << ptr2.get() << endl;
    ptr1.swap(ptr2);
    cout << "ptr1 points to" << ptr1.get() << endl;
    cout << "ptr1 points to" << ptr2.get() << endl;
}