#include <iostream>
#include <string>
using namespace std;

// Base class
class Person
{
public:
    string name;
    int age;

    void getPerson(string n, int a)
    {
        name = n;
        age = a;
    }

    void showPerson()
    {
        cout << "Name : " << name << endl;
        cout << "Age : " << age << endl;
    }
};

// Single inheritance: Person -> Student
class Student : public Person
{
public:
    int rollNo;
    string course;

    void getStudent(int r, string c)
    {
        rollNo = r;
        course = c;
    }

    void showStudent()
    {
        cout << "Roll No : " << rollNo << endl;
        cout << "Course : " << course << endl;
    }
};

// Multilevel inheritance: Person -> Student -> GraduateStudent
class GraduateStudent : public Student
{
public:
    string thesis;

    void getGraduate(string t)
    {
        thesis = t;
    }

    void showGraduate()
    {
        cout << "Thesis : " << thesis << endl;
    }
};

int main()
{
    cout << "--- Single Inheritance (Person -> Student) ---" << endl;
    Student s;
    s.getPerson("Rahul", 19);
    s.getStudent(101, "B.Tech");
    s.showPerson();
    s.showStudent();

    cout << "\n--- Multilevel Inheritance (Person -> Student -> GraduateStudent) ---" << endl;
    GraduateStudent g;
    g.getPerson("Gunjan", 22);
    g.getStudent(201, "M.Tech");
    g.getGraduate("Machine Learning");
    g.showPerson();
    g.showStudent();
    g.showGraduate();

    return 0;
}