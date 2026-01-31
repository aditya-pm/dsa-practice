#pragma once
#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* append_node(int value, ListNode** head, ListNode** tail) {
    ListNode* newNode = new ListNode(value);
    if (*head == nullptr) {
        *head = newNode;
        *tail = newNode;
    } else {
        (*tail)->next = newNode;
        *tail = newNode;
    }
    return newNode;
}

void print_list(ListNode* head) {
    ListNode* temp = head;
    while (temp != nullptr) {
        std::cout << temp->val << "->";
        temp = temp->next;
    }
    std::cout << "nullptr" << std::endl;
}