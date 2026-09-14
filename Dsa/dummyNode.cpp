// ============================================================
// File: dummyNode.cpp
// Folder: Dsa
// Purpose: Merges two sorted linked lists while preserving the sorted order.
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

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

    // Write your solution here
    ListNode* dummy = new ListNode(-1);
    ListNode* tail = dummy;


    while(list1 != nullptr && list2 != nullptr){
      if(list1->val < list2->val){
        tail->next = list1;
        list1 = list1->next;
      }
      else{
        tail->next =list2;
        list2 = list2->next;
      }
      tail = tail->next;
      
      

    }
    return dummy->next;

}