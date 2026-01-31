// 876. Middle of the linked list
#include <iostream>

#include "LinkedList.h"

int nodeCount(ListNode* head) {
    int count = 0;
    ListNode* temp = head;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}

ListNode* middleNode(ListNode* head) {
    int count = nodeCount(head);
    int middleNode = 0;
    ListNode* temp = head;
    if (count % 2 == 0) {
        middleNode = count / 2 + 1;
    } else {
        middleNode = (count + 1) / 2;
    }
    for (int i = 1; i < middleNode; i++) {
        temp = temp->next;
    }
    return temp;
}

ListNode* middleNode2(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;

    // below code returns second middle
    // to get first middle: fast->next!=nullptr && fast->next->next != nullptr
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

int main() {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;

    append_node(10, &head, &tail);
    append_node(20, &head, &tail);
    append_node(30, &head, &tail);
    print_list(head);

    std::cout << middleNode(head)->val << std::endl;
    std::cout << middleNode2(head)->val << std::endl;

    return 0;
}