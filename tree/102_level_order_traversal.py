from include.binary_tree import TreeNode
from typing import Optional
from collections import deque


class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> list[list[int]]:
        if root is None:
            return []

        bfs: list[list[int]] = []
        q: deque[Optional[TreeNode]] = deque([root])

        while q:
            current_level: list[int] = []
            current_level_size = len(q)

            for _ in range(current_level_size):
                current_node = q.popleft()
                current_level.append(current_node.val)

                if current_node.left:
                    q.append(current_node.left)
                if current_node.right:
                    q.append(current_node.right)

            bfs.append(current_level)

        return bfs


def main():
    sol: Solution = Solution()

    root: TreeNode = TreeNode(3)
    node1: TreeNode = TreeNode(9)
    node2: TreeNode = TreeNode(20)
    node3: TreeNode = TreeNode(15)
    node4: TreeNode = TreeNode(7)

    root.left = node1
    root.right = node2
    node2.left = node3
    node2.right = node4

    print(sol.levelOrder(root))


if __name__ == "__main__":
    main()
