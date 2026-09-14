// ============================================================
// File: pallindrome.cpp
// Folder: Dsa
// Purpose: Checks whether a string is a palindrome using two pointers.
// This file is part of the C++ practice repository and is intended for learning.
// ============================================================

#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string s) {

    // Write your solution here
     char* a = &s[0];
     char* e = &s[s.size()-1];
     int count = 0;
     while(a <= e){
        if(*a != *e){
            return false;
        }
        a++;
        e--;
     }
    return true;

}

int main() {

    string s;

    getline(cin, s);

    if (isPalindrome(s))
        cout << "true";
    else
        cout << "false";

    return 0;
}