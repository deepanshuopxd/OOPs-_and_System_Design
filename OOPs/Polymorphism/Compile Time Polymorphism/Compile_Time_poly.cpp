#include <iostream>
using namespace std;

/*
COMPILE TIME POLYMORPHISM
-------------------------
Definition:
Polymorphism where function call is resolved at compile time.

Also called:
- Static Binding
- Early Binding

Achieved using:
1) Function Overloading
2) Operator Overloading

Key Idea:
Same function name, different behavior depending on parameters.
*/

class Math {
public:

    // function overloading (same name, different parameters)

    int add(int a, int b) {
        return a + b;
    }

    int add(int a, int b, int c) {
        return a + b + c;
    }

    double add(double a, double b) {
        return a + b;
    }
};

int main() {

    Math m;

    cout << m.add(2, 3) << endl;        // calls int,int
    cout << m.add(2, 3, 4) << endl;     // calls int,int,int
    cout << m.add(2.5, 3.5) << endl;    // calls double,double

    return 0;
}

/*
NOTES:
- Compiler decides which function to call BEFORE execution
- No runtime overhead
- Improves readability and flexibility
*/