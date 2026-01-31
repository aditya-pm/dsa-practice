#include <unordered_set>

#include "LinkedList.h"

// buffer allowed solution
void remove_dupes_buffer(ListNode* head) {
    if (head == nullptr || head->next == nullptr) return;

    std::unordered_set<int> seen;
    ListNode* curr = head->next;
    ListNode* prev = head;

    seen.insert(head->val);

    while (curr != nullptr) {
        if (seen.count(curr->val)) {
            ListNode* temp = curr;
            prev->next = curr->next;
            curr = curr->next;
            delete temp;
        } else {
            seen.insert(curr->val);
            curr = curr->next;
            prev = prev->next;
        }
    }
}

// no extra space
void remove_dupes(ListNode* head) {
    if (head == nullptr || head->next == nullptr) return;

    ListNode* curr = head;
    while (curr->next != nullptr) {
        ListNode* runner = curr->next;
        ListNode* runner_prev = curr;
        while (runner != nullptr) {
            if (curr->val == runner->val) {
                ListNode* temp = runner;
                runner_prev->next = runner->next;
                runner = runner->next;
                delete temp;
            } else {
                runner = runner->next;
                runner_prev = runner_prev->next;
            }
        }
        curr = curr->next;
    }
}

int main() {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;

    append_node(1, &head, &tail);
    append_node(2, &head, &tail);
    append_node(2, &head, &tail);
    append_node(2, &head, &tail);
    append_node(3, &head, &tail);

    print_list(head);
    remove_dupes(head);
    print_list(head);

    return 0;
}