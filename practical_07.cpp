#include<iostream>
#include<string>
using namespace std;

template <class T>
class Stack
{
    T data[5];
    int top = -1;

public:

    void push(T value)
    {
        if(top == 4)
        {
            cout << "Stack Overflow";
        }
        else
        {
            top++;
            data[top] = value;
        }
    }

    void pop()
    {
        if(top == -1)
        {
            cout << "Stack is Empty";
        }
        else
        {
            top--;
        }
    }

    void display()
    {
        if(top == -1)
        {
            cout << "Stack is Empty";
        }
        else
        {
            for(int i = top; i >= 0; i--)
            {
                cout << data[i] << endl;
            }
        }
    }
};

int main()
{
    Stack<int> s1;

    s1.push(10);
    s1.push(20);
    s1.push(30);

    s1.display();

    return 0;
}