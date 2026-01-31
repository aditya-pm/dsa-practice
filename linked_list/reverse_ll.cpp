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

ListNode* append_node(int value) {
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

void print_list() {
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
    append_node(10);
    append_node(20);
    append_node(30);
    print_list();
    reverseList();
    print_list();

    return 0;
}
