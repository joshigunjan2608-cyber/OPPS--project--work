#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {

    fstream file;
    string line;

    // Writing student records
    file.open("student.csv", ios::out);

    file << "Gunjan,101,90" << endl;
    file << "Khushi,102,85" << endl;
    file << "Abhay,103,80" << endl;

    cout << "Writing Position: " << file.tellp() << endl;

    file.close();

    // Reading student records
    file.open("student.csv", ios::in);

    cout << "\nStudent Records:\n";

    cout << "Reading Position: " << file.tellg() << endl;

    while (getline(file, line)) {
        cout << line << endl;
    }

    file.clear();
    file.seekg(0, ios::beg);

    cout << "\nAfter seekg: " << file.tellg() << endl;

    file.close();

    // Demonstrating seekp()
    file.open("student.csv", ios::out | ios::in);

    file.seekp(0, ios::end);

    cout << "\nWriting Pointer Position: " << file.tellp() << endl;

    file.close();

    return 0;
}