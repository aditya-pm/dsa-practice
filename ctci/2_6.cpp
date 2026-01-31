#include "LinkedList.h"

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
    ListNode* head = nullptr;
    ListNode* tail = nullptr;

    append_node(1, &head, &tail);
    append_node(2, &head, &tail);
    append_node(2, &head, &tail);
    append_node(1, &head, &tail);
    append_node(2, &head, &tail);

    std::cout << is_palindrome(head) << std::endl;

    return 0;
}
