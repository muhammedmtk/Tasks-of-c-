#include <iostream>
#include <cstring>

using namespace std;

class Person {
private:
    int id;
    char name[20];
    int age;

public:
    // Default constructor
    Person() {
        id = 0;
        strcpy(name, "unknown");
        age = 0;
    }

    // Parameterized constructor
    Person(int _id, char* pname, int _age) {
        id = _id;
        strcpy(name, pname);
        age = _age;
    }

    // Setters
    void set_age(int _age) { age = _age; }
    void set_id(int _id) { id = _id; }

    // Getters
    int get_id() { return id; }
    int get_age() { return age; }

    // Print
    void Print() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "ID: " << id << endl;
    }
};

// ---------------------------------------------------

class Student : public Person {
private:
    int grade;

public:
    Student(int _id, char* pname, int _age, int _grade)
        : Person(_id, pname, _age) {
        grade = _grade;
    }

    void Print() {
        Person::Print();
        cout << "Grade: " << grade << endl;
    }
};

// ---------------------------------------------------

class Employee : public Person {
private:
    int salary;

public:
    Employee(int _id, char* pname, int _age, int _salary)
        : Person(_id, pname, _age) {
        set_salary(_salary);
    }

    void set_salary(int _salary) {
        if (_salary < 7000)
            salary = 7000;
        else
            salary = _salary;
    }

    void Print() {
        Person::Print();
        cout << "Salary: " << salary << endl;
    }
};

// ---------------------------------------------------

int main() {
    cout << "=== Student ===" << endl;
    Student s1(1, (char*)"Mohamed", 20, 95);
    s1.Print();

    cout << "\n=== Employee ===" << endl;
    Employee e1(2, (char*)"Tarek", 30, 5000);
    e1.Print();

    return 0;
}
