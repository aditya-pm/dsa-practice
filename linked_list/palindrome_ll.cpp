// 234. Palindrome Linked List
#include <iostream>
#include <vector>

#include "LinkedList.h"

ListNode* head = nullptr;
ListNode* tail = nullptr;

bool isPalindrome(ListNode* head) {
    std::vector<int> vec;
    ListNode* temp = head;

    while (temp != nullptr) {
        vec.push_back(temp->val);
        temp = temp->next;
    }

    for (int i = 0; i < vec.size() / 2; i++) {
        if (vec[i] != vec[vec.size() - i - 1]) return false;
    }

    return true;
}

bool isPalindrome2(ListNode* head) {
    // finding middle
    ListNode* fast = head;
    ListNode* slow = head;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // now slow = middle, reverse from middle
    ListNode* prev = nullptr;
    ListNode* curr = slow;
    ListNode* next = nullptr;
    while (curr != nullptr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    // prev = new head of reversed half
    ListNode* first = head;
    ListNode* second = prev;
    while (second != nullptr) {
        if (first->val != second->val) {
            return false;
        }
        first = first->next;
        second = second->next;
    }

    return true;
}

int main() {
    createNode(1, &head);
    createNode(2, &head);
    createNode(2, &head);
    createNode(1, &head);

    printList(head);
    std::cout << isPalindrome(head) << std::endl;

    return 0;
}
