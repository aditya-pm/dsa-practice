// 141. Linked List Cycle
#include <iostream>

#include "LinkedList.h"

ListNode* head = nullptr;
ListNode* tail = nullptr;

bool hasCycle(ListNode* head) {
    // Floyd's cycle detection algorithm
    // also called Tortoise and Hare algorithm
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        // IMPORTANT: Check for equality only after advancing the pointers.
        // slow and fast start at the same node (head), so checking before
        // movement would always return true even when no cycle exists.

        if (slow == fast) {
            return true;
        }
    }

    return false;
}

int main() {
    createNode(10, &head);
    ListNode* n2 = createNode(20, &head);
    createNode(30, &head);
    printList(head);

    std::cout << hasCycle(head) << std::endl;

    // creating a cycle
    ListNode* n4 = createNode(40, &head);
    n4->next = n2;
    std::cout << hasCycle(head) << std::endl;

    return 0;
}
