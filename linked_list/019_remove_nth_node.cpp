// 19. Remove Nth Node From End of List
#include "LinkedList.h"

class Solution {
   public:
    // double pass
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* curr = head;
        int nodeCount = 0;

        while (curr != nullptr) {
            curr = curr->next;
            nodeCount++;
        }

        int nodeToRemove = nodeCount - n;

        if (nodeToRemove == 0) {
            head = head->next;
            return head;
        }

        curr = head;
        for (int i = 1; i < nodeToRemove; i++) {
            curr = curr->next;
        }

        curr->next = curr->next->next;
        return head;
    }

    // single pass (better)
    ListNode* removeNthFromEndBetter(ListNode* head, int n) {
        ListNode dummy(0, head);
        ListNode* slow = &dummy;
        ListNode* fast = &dummy;

        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }

        while (fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        // slow always points to the node *before* the one we want to remove.
        // if the head must be removed, slow is the dummy node,
        // so slow->next is the original head.
        slow->next = slow->next->next;
        return dummy.next;
    }
};

int main() {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;

    Solution sol;

    // case 1: 1->2->3->4->5->nullptr, n = 2
    ListNode n5(5);
    ListNode n4(4, &n5);
    ListNode n3(3, &n4);
    ListNode n2(2, &n3);
    ListNode n1(1, &n2);
    std::cout << "case 1:\n";
    print_list(&n1);
    ListNode* newHead = sol.removeNthFromEnd(&n1, 2);
    print_list(newHead);

    // case 2: 1 -> nullptr, n = 1
    n1 = ListNode(1);
    std::cout << "\ncase 2:\n";
    print_list(&n1);
    newHead = sol.removeNthFromEnd(&n1, 1);
    print_list(newHead);

    // case 3: 1 -> 2 -> nullptr, n = 1
    n2 = ListNode(2);
    n1 = ListNode(1, &n2);
    std::cout << "\ncase 3:\n";
    print_list(&n1);
    newHead = sol.removeNthFromEnd(&n1, 1);
    print_list(newHead);

    return 0;
}
