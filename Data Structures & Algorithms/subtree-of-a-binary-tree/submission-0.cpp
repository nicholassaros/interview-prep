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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        
        stack<TreeNode*> _stack;
        _stack.push(root);

        while(!_stack.empty()) {
            TreeNode* node = _stack.top();
            _stack.pop();

            if(isSameTree(node, subRoot)) {
                return true;
            }

            if(node) {
                _stack.push(node->left);
                _stack.push(node->right);
            }
        }

        return false;
    }

    bool isSameTree(TreeNode* root, TreeNode* root2) {
        if(!root && !root2) {
            return true;
        }

        if(root && root2 && root->val == root2->val) {
            return isSameTree(root->left, root2->left) && isSameTree(root->right, root2->right);
        }

        return false;
    }
};

/*



check if same tree

*/
