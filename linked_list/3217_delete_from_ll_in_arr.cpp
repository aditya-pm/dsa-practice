// 3217. Delete nodes from linked list present in array
#include <iostream>
#include <unordered_set>
#include <vector>

#include "LinkedList.h"
using namespace std;

ListNode* modifiedList(ListNode* head, vector<int>& nums) {
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
    ListNode* head = nullptr;
    ListNode* tail = nullptr;

    vector<int> nums = {1, 2, 3};

    append_node(1, &head, &tail);
    append_node(2, &head, &tail);
    append_node(3, &head, &tail);
    append_node(4, &head, &tail);
    append_node(5, &head, &tail);
    print_list(head);

    head = modifiedList(head, nums);

    print_list(head);

    return 0;
}
