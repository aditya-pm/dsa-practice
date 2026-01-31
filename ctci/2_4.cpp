#include "LinkedList.h"

ListNode* partition_list(ListNode* head, int x) {
    ListNode* left_head = nullptr;
    ListNode* left_tail = nullptr;
    ListNode* right_head = nullptr;
    ListNode* right_tail = nullptr;

    ListNode* curr = head;
    while (curr != nullptr) {
        ListNode* next = curr->next;
        if (curr->val < x) {
            if (left_head == nullptr) {
                left_head = curr;
                left_tail = curr;
            } else {
                left_tail->next = curr;
                left_tail = curr;
            }
            left_tail->next = nullptr;
        } else {
            if (right_head == nullptr) {
                right_head = curr;
                right_tail = curr;
            } else {
                right_tail->next = curr;
                right_tail = curr;
            }
            right_tail->next = nullptr;
        }

        curr = next;
    }

    if (left_head != nullptr) {
        left_tail->next = right_head;
        return left_head;
    } else {
        return right_head;
    }
}

int main() {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;

    append_node(3, &head, &tail);
    append_node(5, &head, &tail);
    append_node(8, &head, &tail);
    append_node(5, &head, &tail);
    append_node(10, &head, &tail);
    append_node(2, &head, &tail);
    append_node(1, &head, &tail);

    ListNode* partitioned_head = partition_list(head, 5);
    print_list(partitioned_head);

    return 0;
}
