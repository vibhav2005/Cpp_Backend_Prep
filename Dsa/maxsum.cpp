// ============================================================
// File: maxsum.cpp
// Folder: Dsa
// Purpose: Calculates the maximum sum of a contiguous subarray using Kadane's algorithm.
// This file is part of the C++ practice repository and is intended for learning.
// ============================================================

#include <iostream>
#include <vector>

using namespace std;

int maxSubArray(vector<int>& nums) {

    // Write your solution here
    int maxsum = nums[0];
    int currentsum = 0;
    for(int i = 0 ; i <nums.size();i++){
        currentsum += nums[i];

        if(currentsum > maxsum){
            maxsum = currentsum;
        }

        if(currentsum < 0){
            currentsum = 0;
        }
    }
    return maxsum;
}

int main() {

    int n;
    cin >> n;

    vector<int> nums(n);

    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << maxSubArray(nums);

    return 0;
}