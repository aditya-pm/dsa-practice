#include "LinkedList.h"

/*
Why this works:

Assume two singly linked lists A and B that may intersect and therefore may share
a common tail.

Example:
List A: A1 → A2 → A3 → C1 → C2 → C3 → null
List B: B1 → B2 → C1 → C2 → C3 → null

Let:
- a = length of A’s unique prefix
- b = length of B’s unique prefix
- c = length of the shared tail

Pointer ptrA traverses:
A’s unique part (a) + shared tail (c) + B’s unique part (b) = a + c + b

Pointer ptrB traverses:
B’s unique part (b) + shared tail (c) + A’s unique part (a) = b + c + a

Since a + c + b == b + c + a, both pointers traverse the same total distance.
Therefore, when an intersection exists, they are aligned when entering the shared
tail the second time and meet at the intersection node.

If no intersection exists, both pointers eventually become nullptr, and the loop
terminates when ptrA == ptrB == nullptr.
*/

ListNode* get_intersection_node(ListNode* headA, ListNode* headB) {
    if (!headA || !headB) return nullptr;

    ListNode* ptrA = headA;
    ListNode* ptrB = headB;

    while (ptrA != ptrB) {
        if (ptrA == nullptr) {
            ptrA = headB;
        } else {
            ptrA = ptrA->next;
        }

        if (ptrB == nullptr) {
            ptrB = headA;
        } else {
            ptrB = ptrB->next;
        }
    }

    // short form
    // while (ptrA != ptrB) {
    //     ptrA = (ptrA == nullptr) ? headB : ptrA->next;
    //     ptrB = (ptrB == nullptr) ? headA : ptrB->next;
    // }

    // now, ptrA = ptrB, and they are either equal to the inersecting node, or nullptr
    return ptrA;
}