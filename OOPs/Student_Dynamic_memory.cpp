#include <iostream>
using namespace std;
class Student {
public:
    string name;
    int age;
    int *gpa;   // pointer for dynamic memory

    // Parameterized constructor
    Student(string name, int age, int gpa) {
        // Assign normal variables
        this->name = name;
        this->age = age;

        //  Dynamic memory allocation
        this->gpa = new int;     // allocate memory on heap
        *this->gpa = gpa;        // store value in allocated memory

        cout << "Constructor called: Memory allocated for GPA" << endl;
    }

    // Destructor
    ~Student() {
        // Free dynamically allocated memory
        delete gpa;

        cout << "Destructor called: Memory freed for GPA" << endl;
    }

    void display() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "GPA: " << *gpa << endl;  // dereferencing pointer
    }
};

int main() {

    // Dynamic object creation (heap memory)
    Student *s1 = new Student("Vasu", 18, 9);

    // Access using arrow operator (->)
    s1->display();

    // Important: manually delete object
    delete s1;   // calls destructor + frees memory

    return 0;
}