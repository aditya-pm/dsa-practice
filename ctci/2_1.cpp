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

void remove_dupes(ListNode* head) {
}

int main() {
    createNode(10, &head);
    createNode(20, &head);
    createNode(30, &head);
    printList(head);
    return 0;
}