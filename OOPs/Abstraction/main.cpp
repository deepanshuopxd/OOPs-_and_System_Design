#include "bird.h"

int main() {

    // base pointer (abstraction usage)
    Bird *b1 = new Sparrow();
    Bird *b2 = new Eagle();

    Sparrow *sp = new Sparrow(); // can not use as it is private access modifiers.
    // runtime polymorphism
    b1->eat();
    b1->fly();
    b1->sleep();

    cout << endl;

    b2->eat();
    b2->fly();
    b2->sleep();
    
  


    // free memory
    delete b1;
    delete b2;

    return 0;
}