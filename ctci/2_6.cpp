#include "LinkedList.h"

ListNode* head = nullptr;
ListNode* tail = nullptr;

bool is_palindrome(ListNode* head) {
    if (head == nullptr || head->next == nullptr) return true;

    ListNode* slow = head;
    ListNode* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // slow is now at the middle
    // reverse from middle
    ListNode* prev = nullptr;
    ListNode* next = nullptr;
    ListNode* curr = slow;
    while (curr != nullptr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    // prev is now the last node
    ListNode* left = head;
    ListNode* right = prev;
    while (right != nullptr) {
        if (left->val != right->val) return false;
        left = left->next;
        right = right->next;
    }

    return true;
}

int main() {
    createNode(1, &head);
    createNode(2, &head);
    // createNode(3, &head);
    createNode(2, &head);
    createNode(1, &head);
    createNode(2, &head);

    std::cout << is_palindrome(head) << std::endl;

    return 0;
}
