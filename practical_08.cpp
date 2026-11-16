#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> marks = {70, 90, 60, 85};

    // Sorting
    sort(marks.begin(), marks.end());

    cout << "Sorted Marks: ";
    for(int m : marks)
        cout << m << " ";

    // Find_if
    auto it = find_if(marks.begin(), marks.end(),
        [](int m) {
            return m >= 80;
        });

    if(it != marks.end())
        cout << "\nFirst mark above 80: " << *it;

    // Transform
    transform(marks.begin(), marks.end(),
              marks.begin(),
              [](int m) {
                  return m + 5;
              });

    cout << "\nUpdated Marks: ";
    for(int m : marks)
        cout << m << " ";

    // Map
    map<int, int> student;
    student[101] = 85;
    student[102] = 90;

    // Unordered Map
    unordered_map<int, int> data;
    data[101] = 85;
    data[102] = 90;

    return 0;
}