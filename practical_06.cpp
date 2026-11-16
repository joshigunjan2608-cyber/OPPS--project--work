#include <iostream>
using namespace std;

// Function overloading
class Add
{
public:
    int sum(int a, int b)
    {
        return a + b;
    }

    float sum(float a, float b)
    {
        return a + b;
    }

    int sum(int a, int b, int c)
    {
        return a + b + c;
    }
};

// Operator overloading
class Complex
{
    int real, imag;

public:
    Complex()
    {
        real = 0;
        imag = 0;
    }

    Complex(int r, int i)
    {
        real = r;
        imag = i;
    }

    Complex operator+(Complex c)
    {
        Complex temp;
        temp.real = real + c.real;
        temp.imag = imag + c.imag;
        return temp;
    }

    Complex operator-(Complex c)
    {
        Complex temp;
        temp.real = real - c.real;
        temp.imag = imag - c.imag;
        return temp;
    }

    void display()
    {
        cout << real << " + " << imag << "i" << endl;
    }
};

int main()
{
    cout << "--- Function Overloading ---" << endl;
    Add a;
    cout << "Sum of 2 integers : " << a.sum(10, 20) << endl;
    cout << "Sum of 2 floats : " << a.sum(2.5f, 3.5f) << endl;
    cout << "Sum of 3 integers : " << a.sum(1, 2, 3) << endl;

    cout << "\n--- Operator Overloading ---" << endl;
    Complex c1(5, 3), c2(2, 4), c3;

    cout << "c1 = ";
    c1.display();
    cout << "c2 = ";
    c2.display();

    c3 = c1 + c2;
    cout << "c1 + c2 = ";
    c3.display();

    c3 = c1 - c2;
    cout << "c1 - c2 = ";
    c3.display();

    return 0;
}