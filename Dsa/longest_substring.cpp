// ============================================================
// File: longest_substring.cpp
// Folder: Dsa
// Purpose: Finds the length of the longest substring without repeating characters.
// This file is part of the C++ practice repository and is intended for learning.
// ============================================================

#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int lengthOfLongestSubstring(string s) {

    int left = 0;
    int right = 0;
    int maxLen = 0;

    unordered_set<char> st;

    while (right < s.size()) {

        if (st.find(s[right]) == st.end()) {

            st.insert(s[right]);

            maxLen = max(maxLen, right - left + 1);

            right++;
        }
        else {

            st.erase(s[left]);

            left++;
        }
    }

    return maxLen;
}

int main() {

    string s;
    cin >> s;

    cout << lengthOfLongestSubstring(s);

    return 0;
}