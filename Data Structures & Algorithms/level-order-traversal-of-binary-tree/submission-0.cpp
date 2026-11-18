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
        vector<vector<int>> res;
        std::queue<TreeNode*> _queue;
        _queue.push(root);

        while(!_queue.empty()) {
            int queueSize = _queue.size();
            vector<int> level;

            for(int i = 0; i< queueSize; i++) { // Level order traversal
                TreeNode* node = _queue.front();
                _queue.pop();

                if(node == nullptr) {
                    continue;
                }

                _queue.push(node->left);
                _queue.push(node->right);
                

                level.push_back(node->val);
            }

            if(level.size() > 0) {
                res.push_back(level);
            }
        }

        return res;
    }
};
