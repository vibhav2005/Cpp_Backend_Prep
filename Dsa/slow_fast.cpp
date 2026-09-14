// ============================================================
// File: slow_fast.cpp
// Folder: Dsa
// Purpose: Detects cycles in a linked list using the slow/fast pointer method.
// This file is part of the C++ practice repository and is intended for learning.
// ============================================================

#include <iostream>

using namespace std;

struct ListNode {

    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = nullptr;
    }
};

bool hasCycle(ListNode* head) {

    // Write your solution here
    ListNode* slow = head;
    ListNode* fast = head;

    while(fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            return true;

        }

    }
    return false;

}