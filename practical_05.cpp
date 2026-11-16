#include <iostream>
using namespace std;

// Abstract Base Class
class Shape
{
public:
    virtual void area() = 0;
};

// Circle Class
class Circle : public Shape
{
public:
    float radius;

    void area()
    {
        cout << "Circle Area: "
             << 3.14 * radius * radius << endl;
    }
};

// Rectangle Class
class Rectangle : public Shape
{
public:
    float length, breadth;

    void area()
    {
        cout << "Rectangle Area: "
             << length * breadth << endl;
    }
};

// Triangle Class
class Triangle : public Shape
{
public:
    float base, height;

    void area()
    {
        cout << "Triangle Area: "
             << 0.5 * base * height << endl;
    }
};

int main()
{
    Circle c;
    Rectangle r;
    Triangle t;

    c.radius = 5;

    r.length = 10;
    r.breadth = 5;

    t.base = 8;
    t.height = 6;

    Shape* s;

    s = &c;
    s->area();

    s = &r;
    s->area();

    s = &t;
    s->area();

    return 0;
}