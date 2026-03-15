#ifndef STUDENT_H_
#define STUDENT_H_

#include <iostream>
#include <string>
#include <set>
using namespace std;

class Person {
protected:
    string name;
public:
    Person() {}
    Person(string n);
    string getName();
};

class Student : public Person {
private:
    int id;
    double gpa;
    set<string> courses; // لتجنب التكرار
public:
    Student(int i, string n, double g);
    int getId();
    double getGPA();
    void enrollCourse(string course);
    void showCourses();
    void displayStudent();
};

#endif