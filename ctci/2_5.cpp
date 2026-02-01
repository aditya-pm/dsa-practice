#include <cmath>
#include <iostream>

#include "LinkedList.h"

// CASE 1: reversed list
// iterative
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

// recursive
ListNode* sum_lists_recursive(ListNode* l1, ListNode* l2, int carry) {
    if (!l1 && !l2 && carry == 0) return nullptr;

    int sum = carry;
    if (l1) sum += l1->val;
    if (l2) sum += l2->val;

    ListNode* result = new ListNode(sum % 10);
    result->next = sum_lists_recursive(
        l1 ? l1->next : nullptr,
        l2 ? l2->next : nullptr,
        sum / 10);

    return result;
}

// CASE 2: forward list
int ll_length(ListNode* head) {
    int len = 0;
    while (head != nullptr) {
        head = head->next;
        len++;
    }
    return len;
}

ListNode* pad_zeroes(ListNode* head, int count) {
    ListNode* new_head = head;
    for (int i = 0; i < count; i++) {
        ListNode* node = new ListNode(0);
        node->next = new_head;
        new_head = node;
    }
    return new_head;
}

std::pair<int, ListNode*> helper(ListNode* l1, ListNode* l2) {
    // base case: end of both lists
    if (!l1 && !l2) {
        return {0, nullptr};
    }

    // recurse to the end
    auto [carry, next_node] = helper(l1->next, l2->next);

    // add current digits
    int sum = carry + l1->val + l2->val;

    // create current node
    ListNode* current = new ListNode(sum % 10);
    current->next = next_node;

    return {sum / 10, current};
}

ListNode* sum_lists_forward_recursive(ListNode* l1, ListNode* l2) {
    int l1_length = ll_length(l1);
    int l2_length = ll_length(l2);
    int pad_count = std::abs(l1_length - l2_length);

    if (l1_length < l2_length) {
        l1 = pad_zeroes(l1, pad_count);
    } else if (l2_length < l1_length) {
        l2 = pad_zeroes(l2, pad_count);
    }

    // recursive addition
    auto [carry, result] = helper(l1, l2);

    // handle leftover carry
    if (carry > 0) {
        ListNode* head = new ListNode(carry);
        head->next = result;
        return head;
    }

    return result;
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
    std::cout << "+\n";
    print_list(head2);

    std::cout << "sum (iterative): ";
    ListNode* sum_list = sum_lists(head1, head2);
    print_list(sum_list);

    std::cout << "sum (recursive): ";
    ListNode* sum_list_recursive = sum_lists_recursive(head1, head2, 0);  // initial carry = 0
    print_list(sum_list_recursive);

    std::cout << "--------------------\n";

    ListNode* head3 = nullptr;
    ListNode* tail3 = nullptr;

    ListNode* head4 = nullptr;
    ListNode* tail4 = nullptr;

    append_node(6, &head3, &tail3);
    append_node(1, &head3, &tail3);
    append_node(7, &head3, &tail3);

    append_node(2, &head4, &tail4);
    append_node(9, &head4, &tail4);
    append_node(5, &head4, &tail4);

    print_list(head3);
    std::cout << "+\n";
    print_list(head4);

    std::cout << "forward sum (recursive): ";
    ListNode* sum_list_forward_recursive = sum_lists_forward_recursive(head3, head4);
    print_list(sum_list_forward_recursive);

    return 0;
}
