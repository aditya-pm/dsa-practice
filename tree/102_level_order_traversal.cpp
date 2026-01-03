// 102. Binary Tree Level Order Traversal
#include <iostream>
#include <queue>
#include <vector>

#include "BinaryTree.h"
using namespace std;

TreeNode* root = new TreeNode(3);
TreeNode* node1 = new TreeNode(9);
TreeNode* node2 = new TreeNode(20);
TreeNode* node3 = new TreeNode(15);
TreeNode* node4 = new TreeNode(7);

class Solution {
   public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) return {};

        vector<vector<int>> bfs;
        queue<TreeNode*> q;

        q.push(root);
        while (!q.empty()) {
            vector<int> currLevel;
            int currLevelSize = q.size();

            for (int i = 0; i < currLevelSize; i++) {
                TreeNode* currNode = q.front();
                currLevel.push_back(currNode->val);
                q.pop();

                if (currNode->left != nullptr) q.push(currNode->left);
                if (currNode->right != nullptr) q.push(currNode->right);
            }

            bfs.push_back(currLevel);
        }

        return bfs;
    }
};

int main() {
    root->left = node1;
    root->right = node2;
    node2->left = node3;
    node2->right = node4;

    Solution s;
    vector<vector<int>> vec = s.levelOrder(root);

    for (vector<int> innerVec : vec) {
        for (int val : innerVec) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
