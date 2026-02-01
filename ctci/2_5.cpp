#include <iostream>

#include "LinkedList.h"

ListNode* sum_lists(ListNode* l1, ListNode* l2) {
    ListNode dummy(0);
    ListNode* curr = &dummy;

    int carry = 0;
    while (l1 || l2 || carry) {
        int sum = carry;

        if (l1) {
            sum += l1->val;
            l1 = l1->next;
        }

        if (l2) {
            sum += l2->val;
            l2 = l2->next;
        }

        curr->next = new ListNode(sum % 10);
        carry = sum / 10;
        curr = curr->next;
    }

    return dummy.next;
}

int main() {
    ListNode* head1 = nullptr;
    ListNode* tail1 = nullptr;

    ListNode* head2 = nullptr;
    ListNode* tail2 = nullptr;

    append_node(7, &head1, &tail1);
    append_node(1, &head1, &tail1);
    append_node(6, &head1, &tail1);

    append_node(5, &head2, &tail2);
    append_node(9, &head2, &tail2);
    append_node(2, &head2, &tail2);

    print_list(head1);
    std::cout << "+" << std::endl;
    print_list(head2);

    std::cout << "sum:" << std::endl;
    ListNode* sum_list = sum_lists(head1, head2);

    print_list(sum_list);

    return 0;
}
