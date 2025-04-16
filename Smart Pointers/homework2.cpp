#include <iostream>
#include <memory>
using namespace std;

/*struct Deleter
{
    void operator()(int* ptr)
    {
        cout << "My own deleting function";
        delete ptr;
    }
}
shared_ptr<int> CreateInteger(int value)
{
    shared_ptr<int> ptr1 (new int{value});

    return ptr1;
} */

class Person 
{
private:
    int age;
    char name[30];

public:
    Person() = default;
    Person(int age, const char* name)
        :age(age), name("someName")
    {
        cout << "-Destructor\n";
    }
    ~Person()
    {
        cout << "-Destructor\n";
    }
};
int main()
{
    shared_ptr<int> ptr1(new int(1));

    cout << ptr1;

    
    return 0;
}
