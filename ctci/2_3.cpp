#include <LinkedList.h>

void delete_any_middle(ListNode* node) {
    if (node == nullptr || node->next == nullptr) return;

    node->val = node->next->val;
    node->next = node->next->next;
}
