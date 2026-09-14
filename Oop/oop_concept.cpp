// ============================================================
// File: oop_concept.cpp
// Folder: Oop
// Purpose: Covers object-oriented basics such as classes, constructors, and copying.
// This file is part of the C++ practice repository and is intended for learning.
// ============================================================

#include <iostream>

class vehicle{
    protected:
        std::string brand;
        int speed;
    public:
        vehicle(const std::string& brand , int speed);
        virtual void display();
        virtual ~vehicle();
    
};
 
class car: public vehicle{
    private:
        int seats;
    public:
        car(const std::string& brand , int speed , int seats);
        virtual void display();
        virtual ~car();

};

class bike: public vehicle{
    private:
        int enginecc;
    public:
        bike(const std::string& brand , int speed , int enginecc);
        virtual void display();
        virtual ~bike();

};

vehicle::vehicle(const std::string& b, int s):

    brand(b),
    speed(s){};


void vehicle::display(){
    std::cout<<"this is the vehicle";
};

vehicle::~vehicle(){
    std::cout<<"\nparent destructor called";
};

car::car(const std::string& b , int s , int seat):
    vehicle(b,s),
    seats{seat}
{};

void car::display(){
    std::cout<<"car is being displayed\n";
    std::cout<<"brand :"<<brand<<"\n";
    std::cout<<"speed :"<<speed<<"\n";
    std::cout<<"seats :"<<seats<<"\n";
};

car::~car(){
    std::cout<<"car destructor is called";
};


bike::bike(const std::string&  b ,int s , int enginecc):
    vehicle(b,s),
    enginecc(enginecc)
{};

void bike::display(){
    std::cout<<"bike is being displayed\n";
    std::cout<<"brand :"<<brand<<"\n";
    std::cout<<"speed :"<<speed<<"\n";
    std::cout<<"engine cc :"<<enginecc<<"\n";
}
bike::~bike(){
    std::cout<<"bike destrcutor is called";
};




int main(){
    std::cout<<"start inheritence , polymorphism , irtual fucntuion demo \n";

    vehicle* a = new car("BMW",80,4);
    delete a;
    a= new bike("apache",60,320);
    a->display();
    delete a;


    
    return 0;
}