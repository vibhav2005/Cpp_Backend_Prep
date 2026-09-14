// ============================================================
// File: Two_sum.cpp
// Folder: Dsa
// Purpose: Finds two array elements whose sum matches a target value.
// This file is part of the C++ practice repository and is intended for learning.
// ============================================================

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Function to return indices of the two numbers
vector<int> twoSum(vector<int>& nums, int target) {

    // Write your solution here
    unordered_map<int , int> mp;
    for(int i = 0 ; i< nums.size();i++){
        int comp = target - nums[i];
        if(mp.find(comp)!= mp.end()){
            return{mp[comp],i};
        }
        mp[nums[i]] = i;
    }

    return{};

}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int target;
    cin >> target;

    vector<int> ans = twoSum(nums, target);

    cout << ans[0] << " " << ans[1] << endl;

    return 0;
}