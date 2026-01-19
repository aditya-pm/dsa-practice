#include <unordered_set>

#include "LinkedList.h"

ListNode* head = nullptr;
ListNode* tail = nullptr;

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
    createNode(1, &head);
    createNode(2, &head);
    createNode(2, &head);
    createNode(2, &head);
    createNode(3, &head);
    printList(head);
    remove_dupes(head);
    printList(head);

    return 0;
}