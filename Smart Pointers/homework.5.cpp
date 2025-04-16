#include <iostream>
#include <memory>
using namespace std;
class Person
{
private:
    shared_ptr<Person> otherPerson;

public:
    Person()
    {
        cout << "Constructor\n";
    }
    void SetOtherPerson(const shared_ptr<Person>* person)
    {
        otherPerson = person;
    }

    ~Person()
    {
        cout << "Destructor\n";
    }
}

int main()
{
   /*shared_ptr<Room> originRoom{make_shared<Room>{10, 15, 20}};

    weak_ptr<Room> roomObserver{originRoom};

    originRoom.reset();

    shared_ptr<Room> copyRoom{roomObserver.lock()};

    if(copyRoom)
    {
        copyRoom->Draw();
    }*/

   shared_ptr<Person> person1{make_shared<Person>()};
   shared_ptr<Person> person2{make_shared<Person>()};

   person1->SetOtherPerson(person2);
   
   return 0;
}