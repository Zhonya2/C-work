#include <iostream>
#include <memory>
using namespace std;

class Person
{
private:
    int age;
    char name[30];

public:
    Person() = default;
    Person(int age, const char *name)
        : age(age), name("someName")
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
    /*shared_ptr<Person> ptr1(new Person());*/
    shared_ptr<Person> ptr1(new int{5}{1,2,3,4,5});
    shared_ptr<Person> ptr2(nullptr);

    cout << "*ptr1 =" << *ptr1 << endl;
    cout << "*ptr2 =" << *ptr2 << endl;

    ptr1.swap(ptr2);

    cout << "*ptr1 =" << *ptr1 << endl;
    cout << "*ptr2 =" << *ptr2 << endl;
    /*for (size_t i = 0; i < 5; i++)
    {
        cout << ptr1[i] << "";
    }

        /*if (ptr1)
        {
            cout << "Ok";
        }
        prt1->SomeMethod();
        (ptr1).SomeMethod();

        ptr1.operator=() */

    return 0;
}
