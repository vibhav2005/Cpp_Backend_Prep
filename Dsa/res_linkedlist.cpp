// ============================================================
// File: res_linkedlist.cpp
// Folder: Dsa
// Purpose: Reverses a singly linked list and prints the new order.
// This file is part of the C++ practice repository and is intended for learning.
// ============================================================

#include <iostream>

using namespace std;

// Definition for singly-linked list
struct ListNode {

    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = nullptr;
    }
};

// Reverse Function
ListNode* reverseList(ListNode* head) {

    // Write your solution here
    ListNode* current ;
    ListNode* pre = nullptr;
    ListNode* next = nullptr;

    current = head;

    while(current != nullptr){
        next = current->next;
        current->next = pre;
        pre = current;
        current = next;

    }
    return pre;

}

// Insert node at end
void insertNode(ListNode*& head, int value) {

    ListNode* newNode = new ListNode(value);

    if (head == nullptr) {
        head = newNode;
        return;
    }

    ListNode* temp = head;

    while (temp->next != nullptr) {
        temp = temp->next;
    }

    temp->next = newNode;
}

// Print linked list
void printList(ListNode* head) {

    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }

    cout << endl;
}

int main() {

    int n;
    cin >> n;

    ListNode* head = nullptr;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        insertNode(head, x);
    }

    cout << "Original List: ";
    printList(head);

    head = reverseList(head);

    cout << "Reversed List: ";
    printList(head);

    return 0;
}