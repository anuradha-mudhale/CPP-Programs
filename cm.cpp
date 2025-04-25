#include <iostream>
#include <string>

using namespace std;

// Base class: Person
class Person {
protected:
    string name;
    int age;
public:
    Person(string n, int a) : name(n), age(a) {}
    virtual void display() {  // Virtual Function
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

// Derived class: Student (inherits from Person)
class Student : virtual public Person {
protected:
    int rollNumber;
    string branch;
    float marks;
public:
    Student(string n, int a, int r, string b, float m) 
        : Person(n, a), rollNumber(r), branch(b), marks(m) {}

    float calculateCGPA() {
        return marks / 10;
    }

    void display() override {  // Function Overriding
        cout << "Student Details:\n";
        Person::display();
        cout << "Roll Number: " << rollNumber 
             << "\nBranch: " << branch 
             << "\nMarks: " << marks 
             << ", CGPA: " << calculateCGPA() << endl;
    }

    friend class Administration;  // Friend Class Declaration
};

// Derived class: Faculty (inherits from Person)
class Faculty : virtual public Person {
protected:
    int facultyID;
    string department;
    float salary;
public:
    Faculty(string n, int a, int id, string d, float s) 
        : Person(n, a), facultyID(id), department(d), salary(s) {}

    void display() override {  // Function Overriding
        cout << "Faculty Details:\n";
        Person::display();
        cout << "Faculty ID: " << facultyID 
             << "\nDepartment: " << department 
             << "\nSalary: Rs. " << salary << endl;
    }

    friend class Administration;  // Friend Class Declaration
};

// Derived class: TeachingAssistant (Multiple Inheritance)
class TeachingAssistant : public Student, public Faculty {
public:
    TeachingAssistant(string n, int a, int r, string b, float m, int id, string d, float s)
        : Person(n, a), Student(n, a, r, b, m), Faculty(n, a, id, d, s) {}

    void display() override {  // Function Overriding
        cout << "Teaching Assistant Details:\n";
        Person::display();
        cout << "Roll Number: " << rollNumber 
             << "\nBranch: " << branch
             << "\nFaculty ID: " << facultyID 
             << "\nDepartment: " << department 
             << "\nSalary: Rs. " << salary << endl;
    }
};

// Friend Class: Administration
class Administration {
public:
    static void showDetails(Student &s, Faculty &f) {
        cout << "Administration Friend Function:\n";
        cout << "Student " << s.name << " from " << s.branch << " scored " << s.marks << " marks.\n";
        cout << "Faculty " << f.name << " teaches " << f.department << ".\n";
    }
};

// Main Function
int main() {
    // Creating Objects
    Student s("Raj Malhotra", 20, 2023101, "CSE (AI-ML)", 89);
    Faculty f("Dr. A. Sharma", 45, 1001, "Computer Science", 120000);
    TeachingAssistant ta("Priya Desai", 25, 1923105, "CSE (AI-ML)", 85, 2005, "Artificial Intelligence", 35000);

    // Displaying Details
    s.display();
    cout << endl;
    f.display();
    cout << endl;
    ta.display();
    cout << endl;

    // Friend Function Demonstration
    Administration::showDetails(s, f);

    return 0;
}

