# Library Management System (C++)

Console-based Library Management System, Mini Project (Experiment 13) for Object Oriented Programming (C++), Ajeenkya DY Patil University.

*Name:* gunjan joshi | *URN:*e25B000242 | *Division:* B

## Features
- Add books and register members (Student / Faculty)
- Issue and return books
- Search books by title or author
- Show all books sorted A-Z, and show all members
- Error handling using a custom exception

## Member Rules
| Member type | Maximum books |
|---|---|
| Student | 3 |
| Faculty | 5 |

## OOP Concepts Used
- *Encapsulation:* private/protected data in Book and Member
- *Abstraction:* Member is an abstract class (pure virtual functions)
- *Inheritance:* Member -> Student / Faculty
- *Polymorphism:* Student and Faculty override maxBooks() and role()
- *Smart pointers:* shared_ptr<Member>
- *STL:* vector, find_if, sort
- *Exception handling:* LibraryException (thrown in Library, caught in main)

## UML Class Diagram
mermaid
classDiagram
    class Book {
        -int id
        -string title
        -string author
        -bool available
        +issue()
        +giveBack()
    }
    class Member {
        <<abstract>>
        #int id
        #string name
        #int borrowed
        +maxBooks()* int
        +role()* string
    }
    class Student {
        +maxBooks() int
        +role() string
    }
    class Faculty {
        +maxBooks() int
        +role() string
    }
    class Library {
        -vector~Book~ books
        -vector~shared_ptr~Member~~ members
        +addBook()
        +addMember()
        +issueBook()
        +returnBook()
        +searchBook()
    }
    class LibraryException
    Member <|-- Student
    Member <|-- Faculty
    Library o-- Book
    Library o-- Member
    Library ..> LibraryException : throws


## How to Run
bash
g++ -std=c++17 -o library main.cpp
./library


## Screenshots
![Program output](output.png)
