// 206. Reverse Linked List
#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* head = nullptr;
ListNode* tail = nullptr;

ListNode* createNode(int value) {
    ListNode* newNode = new ListNode(value);
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
    return newNode;
}

void printList() {
    ListNode* temp = head;
    while (temp != nullptr) {
        std::cout << temp->val << "->";
        temp = temp->next;
    }
    std::cout << "nullptr" << std::endl;
}

void reverseList() {
    ListNode* prev = nullptr;
    ListNode* curr = head;
    ListNode* next = nullptr;

    while (curr != nullptr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    // prev is the new head
    head = prev;
}

int main() {
    createNode(10);
    createNode(20);
    createNode(30);
    printList();
    reverseList();
    printList();

    return 0;
}
