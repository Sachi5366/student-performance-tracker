#include <iostream>
#include <string>
using namespace std;

struct Student {
    int rollNo;
    string name;
    float marks;
};

int main() {
    const int MAX = 100;
    Student students[MAX];
    int count = 0;
    int choice;

    do {
        cout << "\n--- Student Performance Tracker ---\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Show Topper\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            if (count >= MAX) {
                cout << "Student limit reached!\n";
                continue;
            }
            cout << "Enter Roll Number: ";
            cin >> students[count].rollNo;
            cin.ignore();
            cout << "Enter Name: ";
            getline(cin, students[count].name);
            cout << "Enter Marks: ";
            cin >> students[count].marks;
            count++;
            cout << "Student added!\n";
        }

        else if (choice == 2) {
            if (count == 0) {
                cout << "No students to display.\n";
            } else {
                cout << "\nList of Students:\n";
                for (int i = 0; i < count; i++) {
                    cout << "Roll: " << students[i].rollNo
                         << ", Name: " << students[i].name
                         << ", Marks: " << students[i].marks << endl;
                }
            }
        }

        else if (choice == 3) {
            if (count == 0) {
                cout << "No students to evaluate.\n";
            } else {
                int topperIndex = 0;
                for (int i = 1; i < count; i++) {
                    if (students[i].marks > students[topperIndex].marks) {
                        topperIndex = i;
                    }
                }
                cout << "Topper: " << students[topperIndex].name
                     << " with " << students[topperIndex].marks << " marks.\n";
            }
        }

        else if (choice != 0) {
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 0);

    cout << "Exiting Student Tracker.\n";
    return 0;
}
