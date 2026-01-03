// 160. Intersection of Two Linked Lists

#include <unordered_set>

#include "LinkedList.h"
using namespace std;

class Solution {
   public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        unordered_set<ListNode*> seen;

        // store all nodes of listA
        while (headA != nullptr) {
            seen.insert(headA);
            headA = headA->next;
        }

        // traverse nodes of listB
        while (headB != nullptr) {
            if (seen.count(headB)) return headB;  // intersection
            headB = headB->next;
        }

        return nullptr;  // no intersection
    }

    ListNode* getIntersectionNodeBetter(ListNode* headA, ListNode* headB) {
        ListNode* ptrA = headA;
        ListNode* ptrB = headB;

        // when ptrA and ptrB traverse both the lists entirely, they travel the
        // same distance, hence they become equal at either:
        // 1: intersection node
        // 2: nullptr (no intersection node)
        while (ptrA != ptrB) {
            ptrA = (ptrA == nullptr) ? headB : ptrA->next;
            ptrB = (ptrB == nullptr) ? headA : ptrB->next;
        }

        // when loop is over, a = b = nullptr (no intersection), or a = b = intersection node
        return ptrA;
    }
};