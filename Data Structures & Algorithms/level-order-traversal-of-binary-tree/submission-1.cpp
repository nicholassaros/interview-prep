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
    vector<vector<int>> levelOrder(TreeNode* root) {

        if(root == nullptr) {
            return {};
        }
        
        queue<TreeNode*> _queue;
        _queue.push(root);

        vector<vector<int>> res;

        while(!_queue.empty()) {

            int queueSize = _queue.size();
            vector<int> level;

            for(int i = 0; i < queueSize; i++) {
                TreeNode* node = _queue.front();
                _queue.pop();

                level.push_back(node->val);

                if(node->left != nullptr) {
                    _queue.push(node->left);
                }

                if(node->right != nullptr) {
                    _queue.push(node->right);
                }
            }

            res.push_back(level);
        }

        return res;



    }
};
