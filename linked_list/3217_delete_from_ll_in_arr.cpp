// 3217. Delete nodes from linked list present in array
#include <iostream>
#include <unordered_set>
#include <vector>

#include "LinkedList.h"
using namespace std;

ListNode* head = nullptr;
ListNode* tail = nullptr;

ListNode* modifiedList(vector<int>& nums) {
    unordered_set<int> set(nums.begin(), nums.end());

    ListNode dummy(0);
    dummy.next = head;
    ListNode* curr = &dummy;
    while (curr->next != nullptr) {
        if (set.count(curr->next->val)) {
            curr->next = curr->next->next;
        } else {
            curr = curr->next;
        }
    }

    return dummy.next;  // head might have changed, return new head
}

int main() {
    vector<int> nums = {1, 2, 3};
    createNode(1, &head);
    createNode(2, &head);
    createNode(3, &head);
    createNode(4, &head);
    createNode(5, &head);
    printList(head);

    head = modifiedList(nums);

    printList(head);

    return 0;
}
