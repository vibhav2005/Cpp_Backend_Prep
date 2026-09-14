// ============================================================
// File: Deepcopy.cpp
// Folder: Oop
// Purpose: Illustrates deep-copy behavior for dynamically allocated memory.
// This file is part of the C++ practice repository and is intended for learning.
// ============================================================


//Q2 Dynamic memory allocation (new/delete) in a Student class.
#include <iostream>
using namespace std;


class Student{
    private:
        string name;
        int id;
        int age;
        int *marks;
    public:
        Student();
        ~Student();
        void setStudent( const string& n ,int a , int i,int m);
        Student(const Student& other);
        void display();
        
};

Student::Student():
    name(""),
    id(0),
    age(0)
   
    {
         marks = new int;
         *marks = 0;
    };

Student::~Student(){
    delete marks;

    marks = nullptr;

    std::cout << "Destructor Called\n";
};

Student::Student(const Student& other)
    : name(other.name),
      id(other.id),
      age(other.age)
{
    marks = new int;

    *marks = *(other.marks);

    std::cout << "Copy Constructor Called\n";
}

void Student::display(){
    cout<<"name of student :"<<name<<"\n";
    cout<<"Student id :"<<id<<"\n";
    cout<<"age of student :"<<age<<"\n";
    std::cout << "Marks : " << *marks << '\n';
}
void Student::setStudent(const std::string& name,int age,int id,int m)
{
    this->name = name;
    this->age = age;
    this->id = id;
    *marks = m;
}

int main(){
    Student s;
    s.setStudent("vibhav",21,101,55);
    s.display();
    Student s1 = s;
    s.display();
    s1.display();

    s1.setStudent("abhina",102,101,44);
    s.display();
    s1.display();
    return 0;
}