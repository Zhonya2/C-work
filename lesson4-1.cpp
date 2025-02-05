#include <iostream>
using namespace std;

double ToCube(const double number);

int main() {
    int a = 3;
    double cube = ToCube(a);

    return 0;
}

double ToCube(double number) {
    return number * number * number;
}