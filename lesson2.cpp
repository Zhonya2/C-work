#include <iostream>
using namespace std;
int main() {
    const int WEEKS = 3, DAYS = 2;
    int temperatures[WEEKS][DAYS] = {{10, 20}, {100, 200}, {1000, 2000}};

    for (int i = 0; i < WEEKS; i++)
    {
        for (int j = 0; j < DAYS; j++)
            cout << "temperatures[" << 1 << "][" << j << "] = " << temperatures[i][j] << endl;

        cout << endl;
    }
}