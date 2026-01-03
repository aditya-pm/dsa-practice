# 160. Intersection of Two Linked Lists
from include.linked_list import ListNode
from typing import Optional


class Solution:
    def getIntersectionNode(
        self, headA: ListNode | None, headB: ListNode | None
    ) -> Optional[ListNode]:
        seen: set[ListNode] = set()

        while headA is not None:
            seen.add(headA)
            headA = headA.next

        while headB is not None:
            if headB in seen:
                return headB

            headB = headB.next

        return None

    def getIntersectionNodeBetter(
        self, headA: ListNode | None, headB: ListNode | None
    ) -> Optional[ListNode]:
        ptrA = headA
        ptrB = headB

        while ptrA is not ptrB:
            ptrA = headB if ptrA is None else ptrA.next
            ptrB = headA if ptrB is None else ptrB.next

        return ptrA
