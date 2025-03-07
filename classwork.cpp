#include <iostream>
#include <cmath> 
using namespace std;

class Complex
{
private:
    double real;
    double imag; 

public:
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    Complex operator+(const Complex &other) const
    {
        return Complex(real + other.real, imag + other.imag);
    }

    Complex operator*(const Complex &other) const
    {
        return Complex(real * other.real - imag * other.imag, real * other.imag + imag * other.real);
    }

    void print() const
    {
        cout << real << (imag >= 0 ? "+" : "-") << abs(imag) << endl;
    }
};

int main()
{
    Complex c1(3, 4), c2(1, 2);
    Complex sum = c1 + c2, product = c1 * c2;

    cout << "Сума: ";
    sum.print();

    cout << "Добуток: ";
    product.print();

    return 0;
}