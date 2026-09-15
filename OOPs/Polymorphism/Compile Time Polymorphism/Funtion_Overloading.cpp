#include <iostream>
using namespace std;

/*
FUNCTION OVERLOADING
--------------------
Same function name but:
- different number of parameters
- or different type of parameters

Rules:
- Return type alone cannot differentiate
- Parameters must differ
*/

class Print {

public:

    void show(int x) {
        cout << "Integer: " << x << endl;
    }

    void show(double x) {
        cout << "Double: " << x << endl;
    }

    void show(string x) {
        cout << "String: " << x << endl;
    }

    void show(int x, int y) {
        cout << "Two Integers: " << x << ", " << y << endl;
    }
};

int main() {

    Print p;

    p.show(10);
    p.show(10.5);
    p.show("Deepanshu");
    p.show(5, 6);

    return 0;
}

/*
NOTES:
- Improves code readability
- Avoids multiple function names
- Example real life:
  print() → print int, string, float differently
*/