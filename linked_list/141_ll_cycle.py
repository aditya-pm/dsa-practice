# 141. Linked List Cycle
from include.linked_list import ListNode
from typing import Optional


class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        slow = head
        fast = head

        while fast is not None and fast.next is not None:
            slow = slow.next
            fast = fast.next.next

            if slow is fast:
                return True

        return False

    def hasCycle2(self, head: Optional[ListNode]) -> bool:
        seen: set[ListNode] = set()
        curr = head

        while curr is not None:
            if curr in seen:
                return True
            seen.add(curr)
            curr = curr.next

        return False
