// 108. Convert Sorted Array to Binary Search Tree
#include <vector>

#include "BinaryTree.h"
using namespace std;

class Solution {
   public:
    TreeNode* builder(vector<int>& nums, int left, int right) {
        if (left > right) return nullptr;

        int mid = (left + right) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = builder(nums, left, mid - 1);
        root->right = builder(nums, mid + 1, right);

        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.size() == 0) return nullptr;

        return builder(nums, 0, nums.size() - 1);
    }
};

/*
 * First entire left subtree is built, then the right is built.
 *
 * Example: [-10, -3, 0, 5, 9]
 *             0   1  2  3  4
 *
 * Final Tree:
 *              0
 *             / \
 *         -10     5
 *            \      \
 *            -3      9
 *
 * Flow of execution build(<left>, <right>):
 *
 * build(0, 4) -> mid = 2, root = 0
 *      build(0, 1) -> mid = 0, root = -10
 *           build(0, -1) -> nullptr
 *           build(1, 1) -> mid = 1, root = -3
 *                build(1, 0) -> nullptr
 *                build(2, 1) -> nullptr
 *
 *      build(3, 4) -> mid = 3, root = 5
 *           build(3, 2) -> nullptr
 *           build(4, 4) -> mid = 4, root = 9
 *                build(4, 3) -> nullptr
 *                build(5, 4) -> nullptr
 */
