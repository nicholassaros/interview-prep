/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
struct Balance {
    bool isBalanced;
    int height;
};


class Solution {
public:
    bool isBalanced(TreeNode* root) {

        Balance res = findBalancedTree(root);
        if (res.isBalanced) {
            return true;
        }

        return false;
        
    }

    Balance findBalancedTree(TreeNode* node) {
        if (node == nullptr) {
            return Balance(true, 0);
        }

        Balance left = findBalancedTree(node->left);
        Balance right = findBalancedTree(node->right);

        if (!left.isBalanced || 
            !right.isBalanced ||
            abs(left.height - right.height) > 1) {
            return Balance(false, max(left.height, right.height)+1);
        }

        return Balance(true, max(left.height, right.height)+1);
    }
};


/*
if abs(height(left) - height(right)) <= 1


*/