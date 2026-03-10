/*
 * Assignment 2 / Question 2 / student.c
 * ------------------------------------------------------------
 * Check if a BST is an AVL tree
 *
 * Implement:
 *   bool isAVL(struct TreeNode* root);
 *
 * AVL (for this assignment) means:
 * 1) strict BST property (no duplicates)
 * 2) height-balanced: abs(height(left) - height(right)) <= 1 at every node
 *
 * Rules:
 * - Do NOT allocate new nodes.
 * - Do NOT modify the tree.
 * - Do NOT print anything.
 *
 * Build/Run (from Assignment2 folder):
 *   make run2
 */

#include <stdbool.h>
#include <stddef.h>
#include <limits.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int max(int a, int b) {
    if (a > b) return a;
    return b;
}

int checkAVL(struct TreeNode* node, long long minVal, long long maxVal) {
    if (node == NULL) return true;

    if (node->val <= minVal || node->val >= maxVal) return -1;

    int leftHeight = checkAVL(node->left, minVal, node->val);
    if (leftHeight == -1) return -1;

    int rightHeight = checkAVL(node->right, node->val, maxVal);
    if (rightHeight == -1) return -1;

    if (abs(leftHeight - rightHeight) > 1) return -1;

    return 1 + max(leftHeight, rightHeight);
}

bool isAVL(struct TreeNode* root) {
    return checkAVL(root, LLONG_MIN, LLONG_MAX) != -1;
}
