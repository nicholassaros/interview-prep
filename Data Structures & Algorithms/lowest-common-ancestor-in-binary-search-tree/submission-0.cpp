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
    bool isLowestCommonAncestor(TreeNode* node, TreeNode* p, TreeNode* q) {
        if((p->val >= node->val && q->val <= node->val)
            || (q->val >= node->val && p->val <= node->val)) {
                return true;
            }
        return false;
    }


    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) {
            return nullptr;
        }

        if(isLowestCommonAncestor(root, p, q)) {
            return root;
        }

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        return left != nullptr ? left : right;
    }
};



/*

-- FIND LCA in binary search tree

Binary search tree is where left is strictly less and right is strictly greater
How can these properties help us?

A node is an ancestor node if it its value 

value <= p and value >= q
value <= q and value >= p

*/