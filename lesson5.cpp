#include <iostream>
using namespace std;

void Function();

/* extern int globalVariable = 10;
int arr[3] = {
    1,
    2,
    3,
};

int main() {

    int a;
    int localVariable = 4;
    Function();

    cout << globalVariable << endl;

    return 0;
}*/

int a = 3;

void Function() {
    extern int a;
    cout << a << endl;
}

int main() {

    cout << a;
    for (int i = 0; i < 3; i++){
        Function();
    }

    return 0;
}