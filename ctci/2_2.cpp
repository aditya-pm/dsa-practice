#include <LinkedList.h>

// k = 1 (last node), k = 2 (2nd last node)
ListNode* kth_last(ListNode* head, int k) {
    if (head == nullptr || k <= 0) return nullptr;

    ListNode* slow = head;
    ListNode* fast = head;

    for (int i = 0; i < k; i++) {
        if (fast == nullptr) return nullptr;
        fast = fast->next;
    }

    while (fast != nullptr) {
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}

int helper(ListNode* node, int k, ListNode*& result) {
    if (node == nullptr) return 0;

    int pos_from_last = helper(node->next, k, result) + 1;

    if (pos_from_last == k) {
        result = node;
    }

    return pos_from_last;
}

ListNode* kth_last_recursive(ListNode* head, int k) {
    if (head == nullptr || k <= 0) return nullptr;

    ListNode* result = nullptr;
    helper(head, k, result);
    return result;
}

int main() {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;

    append_node(1, &head, &tail);
    append_node(2, &head, &tail);
    append_node(3, &head, &tail);
    append_node(4, &head, &tail);
    append_node(5, &head, &tail);

    print_list(head);

    std::cout << kth_last(head, 2)->val << std::endl;
    std::cout << kth_last_recursive(head, 2)->val << std::endl;

    return 0;
}
