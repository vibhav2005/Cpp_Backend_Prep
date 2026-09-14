// ============================================================
// File: leftRightProduct.cpp
// Folder: Dsa
// Purpose: Computes the product of all array elements except the current index.
// This file is part of the C++ practice repository and is intended for learning.
// ============================================================

#include <iostream>
#include <vector>

using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {

    // Write your solution here
 
    vector<int> left(nums.size());
    vector<int> right(nums.size());
    vector<int> result(nums.size());
    left[0] = 1;
    right[nums.size()-1] =1;


    for(int i = 1 ; i < nums.size();i++){
        left[i] = left[i-1]*nums[i-1];
    };
    for(int i = nums.size()-2 ;i>=0 ; i--){
        right[i] = right[i+1]*nums[i+1];
    };

    for(int i = 0 ; i<nums.size();i++){
        result[i] = left[i]*right[i];
    };

    return result;
}

int main() {

    int n;
    cin >> n;

    vector<int> nums(n);

    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<int> ans = productExceptSelf(nums);

    for(int x : ans)
        cout << x << " ";

    return 0;
}