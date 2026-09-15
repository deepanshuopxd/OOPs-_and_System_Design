#include <iostream>
using namespace std;

/*
RUNTIME POLYMORPHISM
---------------------
- Achieved using virtual functions
- Function call resolved at runtime
*/

class Animal {
public:

    // virtual function
    virtual void sound() {
        cout << "Animal makes sound" << endl;
    }

    // virtual destructor (important)
    virtual ~Animal() {
        cout << "Animal Destructor\n";
    }
};

class Dog : public Animal {
public:

    // overriding
    void sound() override {
        cout << "Dog barks" << endl;
    }

    ~Dog() {
        cout << "Dog Destructor\n";
    }
};

class Cat : public Animal {
public:

    // overriding
    void sound() override {
        cout << "Cat meows" << endl;
    }

    ~Cat() {
        cout << "Cat Destructor\n";
    }
};

int main() {

    /*
    POINTER OF BASE CLASS
    ----------------------
    Key for runtime polymorphism
    */

    Animal *ptr;

    // dynamic allocation
    ptr = new Dog();
    ptr->sound();   // Dog version called (runtime decision)

    delete ptr;

    cout << "------------------\n";

    ptr = new Cat();
    ptr->sound();   // Cat version called

    delete ptr;

    return 0;
}