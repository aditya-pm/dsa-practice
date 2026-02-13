#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

TreeNode* create_node(int val) {
    TreeNode* node = malloc(sizeof(TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int main(int argc, char* argv[]) {
    TreeNode* root = create_node(0);
    root->left = create_node(1);
    root->right = create_node(2);

    printf("Root: %d\n", root->val);
    printf("Left: %d\n", root->left->val);
    printf("Right: %d\n", root->right->val);

    return 0;
}
