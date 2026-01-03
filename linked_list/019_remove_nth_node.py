# 19. Remove Nth Node From End of List

from include.linked_list import ListNode, print_list
from typing import Optional


class Solution:

    # double pass
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        curr = head
        node_count = 0

        while curr is not None:
            curr = curr.next
            node_count += 1

        node_to_remove = node_count - n
        if node_to_remove == 0:
            head = head.next
            return head

        curr = head
        for _ in range(1, node_to_remove):
            curr = curr.next

        curr.next = curr.next.next
        return head

    # single pass (better)
    def removeNthFromEndBetter(
        self, head: Optional[ListNode], n: int
    ) -> Optional[ListNode]:
        dummy = ListNode(0, head)
        slow = dummy
        fast = dummy

        for _ in range(n):
            fast = fast.next

        while fast.next is not None:
            fast = fast.next
            slow = slow.next

        slow.next = slow.next.next
        return dummy.next


def main():
    sol = Solution()

    # case 1: 1->2->3->4->5->nullptr, n = 2
    n5 = ListNode(5)
    n4 = ListNode(4, n5)
    n3 = ListNode(3, n4)
    n2 = ListNode(2, n3)
    n1 = ListNode(1, n2)
    print("case 1:")
    print_list(n1)
    newHead = sol.removeNthFromEnd(n1, 2)
    print_list(newHead)

    # case 2: 1 -> nullptr, n = 1
    n1 = ListNode(1)
    print("case 2:")
    print_list(n1)
    newHead = sol.removeNthFromEnd(n1, 1)
    print_list(newHead)

    # case 3: 1 -> 2 -> nullptr, n = 1
    n2 = ListNode(2)
    n1 = ListNode(1, n2)
    print("case 3: ")
    print_list(n1)
    newHead = sol.removeNthFromEnd(n1, 1)
    print_list(newHead)


if __name__ == "__main__":
    main()
