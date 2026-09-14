// ============================================================
// File: max_consecutie1s.cpp
// Folder: Dsa
// Purpose: Counts the maximum number of consecutive ones in a binary array.
// This file is part of the C++ practice repository and is intended for learning.
// ============================================================

#include <iostream>
#include <vector>

using namespace std;

int findMaxConsecutiveOnes(vector<int>& nums) {

    // Write your solution here
    int count = 0;
    int m = 0;
    for(int i= 0 ; i < nums.size();i++){
        if((nums[i] == 1)){
            count++;
            m = max(m, count);
        }
         
        else if((nums[i] != 1)){
           
            count = 0;
        }
    }
    return m;

};

int main() {

    int n;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << findMaxConsecutiveOnes(nums);

    return 0;
}