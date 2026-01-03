from typing import Optional


class ListNode:
    def __init__(self, val: int = 0, next: Optional["ListNode"] = None):
        self.val = val
        self.next = next


def print_list(head: ListNode | None) -> None:
    while head is not None:
        print(f"{head.val}->", end="")
        head = head.next
    print("None")
