#include "Student.h"

Person::Person(string n) : name(n) {}
string Person::getName() { return name; }

Student::Student(int i, string n, double g) : Person(n), id(i), gpa(g) {}

int Student::getId() { return id; }
double Student::getGPA() { return gpa; }

void Student::enrollCourse(string course) {
    courses.insert(course);
}

void Student::showCourses() {
    if (courses.empty()) {
        cout << "No courses enrolled.\n";
    }
    else {
        cout << "Courses: ";
        for (auto c : courses) cout << c << " ";
        cout << endl;
    }
}

void Student::displayStudent() {
    cout << "ID: " << id << ", Name: " << name << ", GPA: " << gpa << endl;
}