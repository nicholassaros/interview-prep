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

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return validateBST(root, -1001, 1001);
    }

    bool validateBST(TreeNode* node, int left, int right) {
        if (node == nullptr){ return true; }

        if (!(left < node->val && right > node->val)){
            return false;
        }

        bool left_return = validateBST(node->left, left, node->val);
        bool right_return = validateBST(node->right, node->val, right);

        return (left_return && right_return);
    }
};
