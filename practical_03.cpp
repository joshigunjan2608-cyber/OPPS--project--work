#include <iostream>
using namespace std;

class Student
{
private:
    int rollNo;
    float marks;

public:
    // Default constructor
    Student()
    {
        rollNo = 0;
        marks = 0;
        cout << "Default constructor called" << endl;
    }

    // Parameterized constructor
    Student(int r, float m)
    {
        rollNo = r;
        marks = m;
        cout << "Parameterized constructor called" << endl;
    }

    // Copy constructor
    Student(const Student &s)
    {
        rollNo = s.rollNo;
        marks = s.marks;
        cout << "Copy constructor called" << endl;
    }

    void display()
    {
        cout << "Roll No : " << rollNo << endl;
        cout << "Marks : " << marks << endl;
    }

    // Destructor
    ~Student()
    {
        cout << "Destructor called" << endl;
    }
};

int main()
{
    Student s1;               // default constructor
    Student s2(101, 85.5);    // parameterized constructor
    Student s3(s2);           // copy constructor

    cout << "\nObject s1" << endl;
    s1.display();

    cout << "\nObject s2" << endl;
    s2.display();

    cout << "\nObject s3 (copy of s2)" << endl;
    s3.display();

    cout << endl;
    return 0;
}