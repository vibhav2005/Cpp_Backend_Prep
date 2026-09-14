// ============================================================
// File: CRUD_Op.cpp
// Folder: Oop
// Purpose: Shows a simple student database with CRUD-style operations.
// This file is part of the C++ practice repository and is intended for learning.
// ============================================================


//Q3 CRUD operations using std::vector.

#include <iostream>
#include <vector>
using namespace std;

class Student{
    private:
        string name;
        int id;
        int age;
        int marks;
    public:
        Student();
        ~Student();
        void setStudent( const string& n ,int a , int i,int m);
        void display() const;
        int getId();

};

class StudentDatabase
{
private:
    std::vector<Student> students;

public:
    void addStudent(const Student& student);

    Student* searchStudent(int id);

    bool deleteStudent(int id);

    void displayStudents() const;
};

int Student::getId(){
    return id;

};
void StudentDatabase::addStudent(const Student& student){

    students.push_back(student);
};

Student* StudentDatabase::searchStudent(int id)
{
    for (auto& student : students)
    {
        if (student.getId() == id)
        {
            return &student;
        }
    }

    return nullptr;
};
bool StudentDatabase::deleteStudent(int id){

    for(auto it = students.begin() ; it!= students.end();it++){
        if(it->getId() == id){
            students.erase(it);
            return true;
        }
    }
    return false;
};

void StudentDatabase::displayStudents() const
{
    if (students.empty())
    {
        std::cout << "No students found.\n";
        return;
    }

    for (const auto& student : students)
    {
        student.display();
        std::cout << "-----------------\n";
    }
};

Student::Student():
    name(""),
    id(0),
    age(0),
    marks(0)
   
    {
    };

Student::~Student(){
    std::cout << "Destructor Called\n";
};

void Student::display() const{
    cout<<"name of student :"<<name<<"\n";
    cout<<"Student id :"<<id<<"\n";
    cout<<"age of student :"<<age<<"\n";
    std::cout << "Marks : " << marks << '\n';
}
void Student::setStudent(const std::string& name,int age,int id,int m)
{
    this->name = name;
    this->age = age;
    this->id = id;
    this->marks = m;
}

int main(){

    return 0;
}