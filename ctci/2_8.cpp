#include "LinkedList.h"

/*
Floyd's Cycle Detection — Why this works:

Assume the linked list contains a cycle.

Let:
- a = distance from head to the start of the loop
- c = length of the loop (number of nodes in the cycle)
- x = distance from the loop start to the collision point
      (measured forward inside the loop)

When slow and fast pointers collide:
- slow has traveled (a + x) nodes
- fast has traveled (a + x + k*c) nodes, for some integer k >= 1
  (fast may have completed multiple full laps around the loop)

Since fast moves twice as fast as slow:
    2(a + x) = a + x + k*c
    a + x = k*c
    a = k*c - x

Rewrite k*c - x as:
    k*c - x = (k - 1)*c + (c - x)

Here:
- (k - 1)*c represents full extra laps around the loop.
  Traversing full loops does not change the position inside the cycle,
  so this term is irrelevant for determining the node position.
- (c - x) is the actual forward distance from the collision point
  to the start of the loop.

Removing the useless full laps leaves:
    a = c - x

Thus:
- The pointer at the head is 'a' nodes away from the loop start.
- The pointer at the collision point is also 'a' nodes away from
  the loop start when moving forward in the cycle.

Moving both pointers one step at a time causes them to meet exactly
at the loop start node.
*/

ListNode* loop_detection(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        // cycle present
        if (slow == fast) break;
    }

    // no cycle
    if (fast == nullptr || fast->next == nullptr) return nullptr;

    // continue to find loop node
    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}
