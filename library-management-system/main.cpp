// Library Management System (short version)
// Concepts: classes, inheritance, polymorphism, STL, exceptions, smart pointers
#include <algorithm>
#include <iostream>
#include <limits>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>
using namespace std;

// ---------- Custom exception ----------
class LibraryException : public runtime_error {
public:
    LibraryException(const string& msg) : runtime_error(msg) {}
};

// ---------- Book ----------
class Book {
    int id;
    string title, author;
    bool available;
public:
    Book(int i, string t, string a) : id(i), title(t), author(a), available(true) {}
    int getId() const { return id; }
    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    bool isAvailable() const { return available; }
    void issue() { available = false; }
    void giveBack() { available = true; }
};

// ---------- Member (abstract) -> Student / Faculty ----------
class Member {
protected:
    int id;
    string name;
    int borrowed;
public:
    Member(int i, string n) : id(i), name(n), borrowed(0) {}
    virtual ~Member() {}
    int getId() const { return id; }
    string getName() const { return name; }
    int getBorrowed() const { return borrowed; }
    virtual int maxBooks() const = 0;   // pure virtual -> abstract class
    virtual string role() const = 0;
    bool canBorrow() const { return borrowed < maxBooks(); }
    void borrow() { borrowed++; }
    void giveBack() { borrowed--; }
};

class Student : public Member {
public:
    Student(int i, string n) : Member(i, n) {}
    int maxBooks() const override { return 3; }
    string role() const override { return "Student"; }
};

class Faculty : public Member {
public:
    Faculty(int i, string n) : Member(i, n) {}
    int maxBooks() const override { return 5; }
    string role() const override { return "Faculty"; }
};

// ---------- Library ----------
class Library {
    vector<Book> books;
    vector<shared_ptr<Member>> members;

    Book& findBook(int id) {
        auto it = find_if(books.begin(), books.end(),
                          [id](const Book& b) { return b.getId() == id; });
        if (it == books.end()) throw LibraryException("Book ID not found.");
        return *it;
    }
    Member& findMember(int id) {
        auto it = find_if(members.begin(), members.end(),
                          [id](const shared_ptr<Member>& m) { return m->getId() == id; });
        if (it == members.end()) throw LibraryException("Member ID not found.");
        return **it;
    }
    void printBook(const Book& b) const {
        cout << "  [" << b.getId() << "] " << b.getTitle() << " by " << b.getAuthor()
             << " - " << (b.isAvailable() ? "Available" : "Issued") << "\n";
    }
public:
    void addBook(const string& title, const string& author) {
        books.push_back(Book(books.size() + 1, title, author));
        cout << "  Book added with ID " << books.size() << "\n";
    }
    void addMember(int type, const string& name) {
        int id = members.size() + 1;
        if (type == 1) members.push_back(make_shared<Student>(id, name));
        else           members.push_back(make_shared<Faculty>(id, name));
        cout << "  Member added with ID " << id << "\n";
    }
    void issueBook(int bookId, int memberId) {
        Book& b = findBook(bookId);
        Member& m = findMember(memberId);
        if (!b.isAvailable()) throw LibraryException("Book is already issued.");
        if (!m.canBorrow()) throw LibraryException(m.getName() + " reached the limit of " +
                                                   to_string(m.maxBooks()) + " books.");
        b.issue();
        m.borrow();
        cout << "  Issued '" << b.getTitle() << "' to " << m.getName() << "\n";
    }
    void returnBook(int bookId, int memberId) {
        Book& b = findBook(bookId);
        Member& m = findMember(memberId);
        if (b.isAvailable()) throw LibraryException("This book was not issued.");
        b.giveBack();
        m.giveBack();
        cout << "  Returned '" << b.getTitle() << "'\n";
    }
    void searchBook(const string& key) const {
        bool found = false;
        for (const auto& b : books)
            if (b.getTitle().find(key) != string::npos || b.getAuthor().find(key) != string::npos) {
                printBook(b);
                found = true;
            }
        if (!found) cout << "  No book found.\n";
    }
    void showBooks() const {
        vector<Book> sorted = books;   // sort by title (A-Z)
        sort(sorted.begin(), sorted.end(),
             [](const Book& a, const Book& b) { return a.getTitle() < b.getTitle(); });
        if (sorted.empty()) cout << "  No books yet.\n";
        for (const auto& b : sorted) printBook(b);
    }
    void showMembers() const {
        if (members.empty()) cout << "  No members yet.\n";
        for (const auto& m : members)
            cout << "  [" << m->getId() << "] " << m->getName() << " (" << m->role() << ") "
                 << m->getBorrowed() << "/" << m->maxBooks() << " books\n";
    }
};

// ---------- Input helpers ----------
int readInt(const string& prompt) {
    int x;
    cout << prompt;
    if (!(cin >> x)) { cin.clear(); x = -1; }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return x;
}
string readText(const string& prompt) {
    string s;
    cout << prompt;
    getline(cin, s);
    return s;
}

// ---------- main ----------
int main() {
    Library lib;
    int choice = -1;
    while (choice != 0) {
        cout << "\n===== LIBRARY MENU =====\n"
             << "1. Add book\n2. Add member\n3. Issue book\n4. Return book\n"
             << "5. Search book\n6. Show books\n7. Show members\n0. Exit\n";
        choice = readInt("Choice: ");
        try {
            if (choice == 1) {
                string t = readText("Title: ");
                string a = readText("Author: ");
                lib.addBook(t, a);
            } else if (choice == 2) {
                string n = readText("Name: ");
                int type = readInt("Type (1=Student, 2=Faculty): ");
                lib.addMember(type, n);
            } else if (choice == 3) {
                int b = readInt("Book ID: ");
                int m = readInt("Member ID: ");
                lib.issueBook(b, m);
            } else if (choice == 4) {
                int b = readInt("Book ID: ");
                int m = readInt("Member ID: ");
                lib.returnBook(b, m);
            } else if (choice == 5) {
                lib.searchBook(readText("Search: "));
            } else if (choice == 6) {
                lib.showBooks();
            } else if (choice == 7) {
                lib.showMembers();
            } else if (choice != 0) {
                cout << "  Invalid choice.\n";
            }
        } catch (const LibraryException& e) {
            cout << "  [Error] " << e.what() << "\n";
        }
    }
    cout << "Goodbye!\n";
    return 0;
} 