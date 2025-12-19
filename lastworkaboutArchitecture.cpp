#include <iostream>

int main()
{
    int var_a;
    int ebx;

    std::cout << "Enter var_a: ";
    std::cin >> var_a;

    std::cout << "Enter ebx: ";
    std::cin >> ebx;

    if (var_a == 10)
    {
        ebx = ebx + 1;
    }
    else
    {
        ebx = ebx - 1;
    }

    std::cout << "Result ebx = " << ebx << std::endl;

    return 0;
}