#ifndef BIRD_H
#define BIRD_H

#include <iostream>
using namespace std;

// Abstract Class
class Bird {
public:
    // pure virtual functions (no implementation)
    virtual void eat() = 0;
    virtual void fly() = 0;
    virtual void sleep() = 0;

    // virtual destructor (important for base class)
    virtual ~Bird() {}
};

/*
NOTES:
- Bird is abstract class
- Cannot create object of Bird
- Only used as interface/blueprint
*/

// ================= CHILD CLASS 1 =================
class Sparrow : public Bird {
private:
    // private data → hidden implementation
    string type = "Small Bird";


    // overriding all pure virtual functions
    void eat() override {
        cout << "Sparrow eats grains\n";
    }

    void fly() override {
        cout << "Sparrow flies at low height\n";
    }

    void sleep() override {
        cout << "Sparrow sleeps in nest\n";
    }
};

/*
NOTES:
- Sparrow MUST implement all functions
- Otherwise it will also become abstract
*/


// ================= CHILD CLASS 2 =================
class Eagle : public Bird {
private:
    string type = "Predator Bird";


    void eat() override {
        cout << "Eagle eats meat\n";
    }

    void fly() override {
        cout << "Eagle flies very high\n";
    }

    void sleep() override {
        cout << "Eagle sleeps on cliffs\n";
    }
};

/*
NOTES:
- Same interface, different implementation
- This is abstraction + polymorphism
*/

#endif