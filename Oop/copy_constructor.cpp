// ============================================================
// File: copy_constructor.cpp
// Folder: Oop
// Purpose: Demonstrates how a copy constructor works in C++.
// This file is part of the C++ practice repository and is intended for learning.
// ============================================================

#include <iostream>

class Student
{
private:
    std::string name;
    int age;

public:
    Student(const std::string& name, int age);

    Student(const Student& other);

    void display() const;
};

Student::Student(const std::string& name, int age): 
    name(name),
      age(age)
{
    std::cout << "Parameterized Constructor Called\n";
}

// -----------------------------

Student::Student(const Student& other)
    : name(other.name),
      age(other.age)
{
    std::cout << "Copy Constructor Called\n";
}

// -----------------------------

void Student::display() const
{
    std::cout << "Name : " << name << '\n';
    std::cout << "Age  : " << age << '\n';
}



int main(){
    Student s1("ajay",22);
    Student s2 = s1;
    s2.display();


    return 0;
}