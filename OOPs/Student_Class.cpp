#include <iostream>
using namespace std;

class Student{
    // Access Modifiers -> 1) public 2) private 3) protected 
    public:
        //  Attributes -> state and properties of an object
        int id,age,nos;
        string name;
        int *gpa;

        // Constructor -> By default called 
        // But if you want to call manually then ->
        Student(){
            cout<<this->name<<" Student Default Constructor Called"<<endl;
        }
        // Parameterised Constructor
        Student(int id,int age,string name,int nos,float gpa){
            cout<<this->name<<" Parameterised Constructor Called."<<endl;
            this->age = age;
            this->id = id;
            this->name = name;
            this->nos = nos;
            this->gpa = new int(gpa);
        }
        //  Copy Constructor
        Student(const Student &srcobj) // srcobj => jisse object se copy krna hai
        //                                                                             
        {
            cout<<this->name<<" Student Copy Constructor Called."<<endl;
            this->age = srcobj.age;
            this->id = srcobj.id;
            this->name = srcobj.name;
            this->nos = srcobj.nos;
            
        }


        // Behaviour -> Methods / functions of object
        void study(){
            cout <<this->name<<" Studying "<<endl;
        }
        void bunk(){
            cout <<this->name<<" Bunking "<<endl;
        }
        void sleep(){
            cout <<this->name<<" Sleeping "<<endl;
        }

        // Destructor -> Like constructor it is also called by default

        ~Student(){
            
            cout<<this->name<<" Student Default Destructor called"<<endl;
            delete this->gpa;
        }
    
};
int main(){

    // Student A;
    // A.id =1;
    // A.name = "Dee";
    // A.age = 22;
    // A.nos = 6;
    // A.study();
    // Student B;
    // B.id =2;
    // B.name = "Deepu";
    // B.age = 22;
    // B.nos = 6;
    // B.bunk();

    //  Paramterised Constructor Object calling 
    // Student A(10,22,"Deepanshu",5);
    // Student B(11,21,"Dee",5);
    // Student C(12,20,"Deep",5);
    // Student D(13,19,"Deepu",5);

    // cout<<A.name<<"\n" <<A.age<<endl;
    // A.bunk();
    // D.sleep();
    
     // Copy Constructor

    // Student Copy = A;
    // cout<<Copy.name<<"\n" <<Copy.age<<endl;
    // Student Copy1(A);
    // cout<<Copy1.name<<"\n" <<Copy1.age<<endl;
   
    //  Dynamic Allocation or Student Pointer;
    Student *A = new Student(1,18,"Vasu",6,9.8);
    cout<<A->name<<endl; // accessed using arrow
    cout<<A->age<<endl;
    A->study();
    // freeing the memory
    delete A; // destructor called 
    return 0;


}
