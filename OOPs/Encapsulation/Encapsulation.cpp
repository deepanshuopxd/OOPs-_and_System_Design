#include <iostream>
using namespace std;

class Student {
private:
    // private data (data hiding)
    int id;
    int age;
    int nos;
    string gf;
    string name;
    float *gpa;
    // private method
    void gfChatting() {
        cout << name << " chatting with "<<gf << endl;
    }
public:
    // constructor
    Student(int id, int age, int nos, string name, string gf,float gpa) {
        this->id = id;
        this->age = age;
        this->nos = nos;
        this->name = name;
        this->gf = gf;
        this->gpa = new float; //allocates memory
        *this->gpa = gpa; // stores value inside it
    }
    // setter
    void setAge(int age) {
        if (age > 0)
            this->age = age;
    }
    // getter
    int getAge() {
        return age;
    }
    void setGpa(float gpa){
        if(gpa > 0 && gpa <= 10){

        if(this->gpa == nullptr){
            this->gpa = new float;
        }

        *this->gpa = gpa;   // update value
    }
    }
    float getGpa(){
        return *gpa; // * -> dereferencing operator (used to access the value stored at the memory address held by a pointer. )
    }
    string getName() {
        return name;
    }
    string getGf(){
        return gf;
    }
    // public methods
    void study() {
        cout << name << " studying" << endl;
    }
    void sleep() {
        cout << name << " sleeping" << endl;
    }
    // controlled access to private method
    void accessGF() {
        gfChatting();
    }
    ~Student(){
        delete gpa;  
    }
};

int main() {

    Student A(1, 20, 5, "Deepanshu", "V",9.1);

    // direct access not allowed
    // A.age = 30;  // error

    // access via methods
    A.setAge(25);
    cout<<A.getGpa()<<endl;
    cout << A.getName() << endl;
    cout << A.getGf() << endl;
    A.setGpa(10);
    cout<<A.getGpa()<<endl;
    A.study();
    A.sleep();

    // private method accessed indirectly
    A.accessGF();

    return 0;
}