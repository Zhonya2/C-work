#include <iostream>
using namespace std;

void Draw() 
{

}

~Room()
{
    cout << "Room was destroyed\n";
}
int main()
{
    /*int* ptr = new int{10};

    int* observer = ptr;

    delete ptr;

    *observer = 20; shared_ptr<A> sharedPtr1{make_shared<A>()};
    shared_ptr<A> sharedPtr2{make_shared<A>()};

    weak_ptr<A> weakPtr1{sharedPtr1};
    weak_ptr<A> weakPtr2{sharedPtr2};

    weakPtr2.reset();*/

    shared_ptr<Room> originRoom{make_shared<Room>(10, 15, 20)};

    weak

    weak_ptr<Room> roomObserver{originRoom};

    originRoom.reset();

    shared_ptr<Room> copyRoom{roomObserver.lock()};

    if(copyRoom)
    {
        copyRoom->Draw();
    }
    return 0;
}