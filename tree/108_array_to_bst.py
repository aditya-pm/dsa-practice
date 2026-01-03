# 108. Converted Sorted Array to Binary Search Tree
from include.binary_tree import TreeNode
from typing import Optional


class Solution:
    def builder(self, nums, left, right) -> Optional[TreeNode]:
        if left > right:
            return None

        mid: int = int((left + right) / 2)
        root: TreeNode = TreeNode(nums[mid])
        root.left = self.builder(nums, left, mid - 1)
        root.right = self.builder(nums, mid + 1, right)
        return root

    def sortedArrayToBST(self, nums: list[int]) -> Optional[TreeNode]:
        if not nums:
            return None

        return self.builder(nums, 0, len(nums) - 1)
