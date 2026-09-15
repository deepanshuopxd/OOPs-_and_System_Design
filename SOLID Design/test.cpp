#include <iostream>
using namespace std;

class Bird {
public:
    virtual void fly() {
        cout << "Flying\n";
    }
};

class Penguin : public Bird {
public:
    void fly() override {
        throw runtime_error("Penguins can't fly");
    }
    void hello(){
        cout<<"hello"<<endl;
    }
};

int main(){
    Bird* b = new Penguin();
    b->fly();
    b->hello();
}