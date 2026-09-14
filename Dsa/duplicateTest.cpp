// ============================================================
// File: duplicateTest.cpp
// Folder: Dsa
// Purpose: Checks whether an array contains duplicate values using a hash set.
// This file is part of the C++ practice repository and is intended for learning.
// ============================================================

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

bool containsDuplicate(vector<int>& nums) {

    // Write your solution here
    unordered_set<int> st;

    for(int i = 0 ; i <nums.size();i++){
        if(st.find(nums[i]) == st.end()){
            st.insert(nums[i]);
        }
    }
    if(st.size() < nums.size()){
        return true;
    }
    return false;

}

int main() {

    int n;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    if (containsDuplicate(nums))
        cout << "true";
    else
        cout << "false";

    return 0;
}