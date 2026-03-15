#include <iostream>
#include <vector>
#include <algorithm>
#include "Student.h"
using namespace std;

class StudentManagementSystem {
private:
    vector<Student> students;
public:
    void addStudent() {
        int id;
        string name;
        double gpa;
        cout << "Enter Student ID: "; cin >> id;
        auto it = find_if(students.begin(), students.end(), [&](Student& s) { return s.getId() == id; });
        if (it != students.end()) { cout << "ID already exists!\n"; return; }
        cin.ignore();
        cout << "Enter Name: "; getline(cin, name);
        cout << "Enter GPA: "; cin >> gpa;
        if (gpa < 0.0 || gpa > 4.0) { cout << "Invalid GPA!\n"; return; }
        students.push_back(Student(id, name, gpa));
        cout << "Student added successfully.\n";
    }

    void removeStudent() {
        int id; cout << "Enter Student ID to remove: "; cin >> id;
        auto it = remove_if(students.begin(), students.end(), [&](Student& s) { return s.getId() == id; });
        if (it != students.end()) {
            students.erase(it, students.end());
            cout << "Student removed.\n";
        }
        else cout << "Student not found.\n";
    }

    void searchStudent() {
        int id; cout << "Enter Student ID to search: "; cin >> id;
        auto it = find_if(students.begin(), students.end(), [&](Student& s) { return s.getId() == id; });
        if (it != students.end()) it->displayStudent();
        else cout << "Student not found.\n";
    }

    void displayAll() {
        for (auto& s : students) s.displayStudent();
    }

    void enrollStudentInCourse() {
        int id; string course;
        cout << "Enter Student ID: "; cin >> id;
        auto it = find_if(students.begin(), students.end(), [&](Student& s) { return s.getId() == id; });
        if (it != students.end()) {
            cin.ignore();
            cout << "Enter Course Name: "; getline(cin, course);
            it->enrollCourse(course);
            cout << "Course added.\n";
        }
        else cout << "Student not found.\n";
    }

    void showStudentCourses() {
        int id; cout << "Enter Student ID: "; cin >> id;
        auto it = find_if(students.begin(), students.end(), [&](Student& s) { return s.getId() == id; });
        if (it != students.end()) it->showCourses();
        else cout << "Student not found.\n";
    }

    void sortStudentsByGPA() {
        sort(students.begin(), students.end(), [](Student& a, Student& b) { return a.getGPA() > b.getGPA(); });
        cout << "Students sorted by GPA.\n";
    }

    void menu() {
        int choice;
        do {
            cout << "\n--- Student Management System ---\n";
            cout << "1. Add Student\n2. Remove Student\n3. Search Student\n4. Display All Students\n";
            cout << "5. Enroll Student in Course\n6. Show Student Courses\n7. Sort Students by GPA\n8. Exit\n";
            cout << "Choice: "; cin >> choice;
            switch (choice) {
            case 1: addStudent(); break;
            case 2: removeStudent(); break;
            case 3: searchStudent(); break;
            case 4: displayAll(); break;
            case 5: enrollStudentInCourse(); break;
            case 6: showStudentCourses(); break;
            case 7: sortStudentsByGPA(); break;
            case 8: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice.\n";
            }
        } while (choice != 8);
    }
};

int main() {
    StudentManagementSystem sms;
    sms.menu();
    return 0;
}