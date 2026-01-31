// 141. Linked List Cycle
#include <iostream>

#include "LinkedList.h"

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
    ListNode* head = nullptr;
    ListNode* tail = nullptr;

    append_node(10, &head, &tail);
    ListNode* n2 = append_node(20, &head, &tail);
    append_node(30, &head, &tail);
    print_list(head);

    std::cout << hasCycle(head) << std::endl;

    // creating a cycle
    ListNode* n4 = append_node(40, &head, &tail);
    n4->next = n2;
    std::cout << hasCycle(head) << std::endl;

    return 0;
}
