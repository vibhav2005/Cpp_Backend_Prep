// ============================================================
// File: swap_by_ref.cpp
// Folder: Oop
// Purpose: Swaps two integers by passing them by reference.
// This file is part of the C++ practice repository and is intended for learning.
// ============================================================

//Swap two numbers using references.
#include <iostream>
using namespace std;

void swap(int& a , int& b){
    int temp ;
    temp = a;
    a = b;
    b = temp;

}

int main(){
    int a , b;
    a = 100;
    b= 200;
    swap(a,b);
    printf("a :%d , b: %d ",a,b);
    return 0;
}
